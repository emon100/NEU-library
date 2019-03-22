//
// Created by 王一蒙 on 2019/3/12 0012.
//
#include "lib.h"

//借还书功能函数

void  reader_center(book_list *book_data,person *user){
    //printf("reader_center\n");
    //printf("Press any key to continue:\n");
    int choice;
    penalty(book_data,user);
    printf("\t\t\t[1]修改私人信息\n"
           "\t\t\t[2]借书\n"
           "\t\t\t[3]还书\n"
           "\t\t\t[4]返回上级菜单\n");
    while(1){
        fflush(stdin);
        choice=getchar();
        fflush(stdin);
        switch(choice){
            case   '1':
                //显示个人信息+修改
                self_manage(book_data,user);
                break;
            case   '2':
                //借书
                borrow_book(book_data,user);
                break;
            case   '3':
                //还书
                return_book(book_data,user);
                break;
            case   '4':
                //返回上一层
                system("cls");
                return;
            default:
                system("cls");
                printf("请再次输入:\n");
                break;
        }
        printf("\t\t\t[1]修改私人信息\n"
                "\t\t\t[2]借书\n"
                "\t\t\t[3]还书\n"
                "\t\t\t[4]返回上级菜单\n");
    }
}

void self_manage(book_list *book_data,person *user) {
    int borrow_quantity = user->borrow_quantity;
    int exit_flag = 0;
    int option;
    system("cls");
    penalty(book_data,user);
    display_person_pointer(user);
    for (int i = 0; i < borrow_quantity; ++i) {
        if(i==0)printf("\t\t\t--------已借书籍--------\n");
        printf("书本编号:%d\n", user->book_code[i]);
        //display(book_code)展示书籍信息
        display_book_code(user->book_code[i], book_data);
    }
    while (1) {
        if (exit_flag != 1) {
            printf("请选择要修改的信息类型：\n[1]图书卡密码\n[2]人员姓名\n[3]人员性别\n[4]返回上一级菜单\n");
            fflush(stdin);
            option = getchar();
            fflush(stdin);
            switch (option) {
                case '1': {
                    printf("输入新的密码:");//这个起码得有个确认的过程吧
                    gets(user->password);
                    fflush(stdin);
                    break;
                }
                case '2': {
                    printf("输入新的姓名:");
                    gets(user->name);
                    fflush(stdin);
                    break;
                }
                case '3': {
                    printf("输入新的性别([0]男性[1]女性):");
                    scanf("%d", &user->sex);
                    fflush(stdin);
                    break;
                }
                case '4': {
                    system("cls");
                    return;
                }
                default:
                    printf("输入错误!请再次输入:");
                    break;
            }
        }
        //显示用户信息
        system("cls");
        penalty(book_data,user);
        display_person_pointer(user);
        for (int i = 0; i < borrow_quantity; ++i) {
            if(i==0)printf("\t\t\t--------已借书籍--------\n");
            printf("书籍编号:%d\n", user->book_code[i]);
            display_book_code(user->book_code[i], book_data);
        }
        //输入判断
        if (exit_flag == 1)printf("输入错误!请再次输入:");
        exit_flag = 0;
        //询问是否继续
        printf("是否继续？ [1]是  [0]否\n");
        option = getchar();
        fflush(stdin);
        if (option == '0') {
            system("cls");
            return;
        }
        else if (option == '1') {
            continue;
        }
        else {
            exit_flag = 1;
            continue;
        }
    }
}

//罚金计算函数，超出时间一天0.2元
void penalty(book_list *book_data,person *user){
    int         borrow_quantity=user->borrow_quantity;
    float       penalty=0;
    book        *borrowed_book=NULL;
    time_t      now,diff;
    now=time(NULL);
    for (int i=0;i<borrow_quantity;++i){
        borrowed_book=search_book_pointer(user->book_code[i],book_data);
        diff=(now-(borrowed_book->borrow_time+5097600));//计算现在时间与应还时间差值
        if(diff>0)penalty=penalty+(diff/86400)*0.2;
        else continue;
    }
    if(user->penalty<penalty)user->penalty=penalty;
}


void borrow_book(book_list *book_data,person *user){
    int         code;
    char        choice;
    book        *current_book=NULL;

    system("cls");
    fflush(stdin);
    penalty(book_data,user);
    while(1){
        if(user->penalty>0||user->borrow_quantity>=10){
            printf("您无法借书,因为你已经借了超过10本书籍或者您有罚金需要支付!\n");
            return;
        }
        else{
            printf("输入您想要借的书籍的编码:\n");
            scanf("%d",&code);
            fflush(stdin);
            current_book = search_book_pointer(code,book_data);
            display_book_pointer(current_book);
            printf("这是您想要借的书籍吗? 输入 1 以继续, 输入其他内容以取消此次操作:\n");
            choice=getchar();
            fflush(stdin);
            if(choice!='1'){
                system("cls");
                printf("本次借书已取消!\n");
                return;
            }
            if(current_book!=NULL){
               if(current_book->person_id_number==-1){
                   user->borrow_quantity++;
                   user->book_code[user->borrow_quantity]=code;
                   current_book->person_id_number=user->id_number;
                   current_book->borrow_time=time(NULL);
                   book_data->book_borrowed++;
                   printf("借书成功!\n");
               }
               else if(current_book->person_id_number!=-1){
                   printf("抱歉,此书已经出借.\n");
               }
            }
            else {
                printf("并未找到这本书籍!\n");
            }
            printf("是否要继续? 输入 1 来借另一本书籍, 输入其他内容以退出.\n");
            choice=getchar();
            fflush(stdin);
            if(choice=='1')continue;
            else {
                system("cls");
                return;
            }
        }
    }
}

void return_book(book_list *book_data,person *user){
    int         code;
    int         borrow_quantity=user->borrow_quantity;
    int         i;
    char        choice;
    book        *current_book=NULL;
    system("cls");
    fflush(stdin);
    if(user->borrow_quantity>0){
        while(1){
            printf("输入您想要归还的书籍的编码:\n");
           scanf("%d",&code);
            fflush(stdin);
           current_book=search_book_pointer(code,book_data);
           if(current_book!=NULL&&current_book->person_id_number==user->id_number){
                //先找元素，把这个元素从数组的某一个地方找到
                for(i=0;i<borrow_quantity;++i){
                   if(user->book_code[i]==code){
                       user->book_code[i]=0;
                       break;
                   }
                }
                //找到后把后一个元素向前移动
                for(;i<borrow_quantity-1;++i){
                     if((i+1)<borrow_quantity){
                        user->book_code[i]=user->book_code[i+1];
                     }
                     else break;
                }
                user->borrow_quantity--;
                current_book->person_id_number=-1;
                book_data->book_borrowed--;
                printf("还书成功!\n");
           }
           else if(current_book==NULL){
               printf("并未找到这本书籍!\n输入任意内容以继续:\n");
               getchar();
               fflush(stdin);
           }
           else {
               printf("您不能归还此书!\n输入任意内容以继续:\n");
               getchar();
               fflush(stdin);
           }
            printf("是否要继续? 输入 1 以归还另一本书籍, 输入其他内容以退出.\n");
            choice=getchar();
            fflush(stdin);
            if(choice=='1')continue;
            else {
                system("cls");
                return;
            }
        }
    }
    else{
        printf("您并没有书籍要归还!\n输入任意内容以返回菜单.\n");
        getchar();
        fflush(stdin);
        return;
    }
}
