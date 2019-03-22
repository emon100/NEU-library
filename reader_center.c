//
// Created by ��һ�� on 2019/3/12 0012.
//
#include "lib.h"

//�軹�鹦�ܺ���

void  reader_center(book_list *book_data,person *user){
    //printf("reader_center\n");
    //printf("Press any key to continue:\n");
    int choice;
    printf("\t\t\t[1]Manage personal info---[2]Borrow book\n"
           "\t\t\t[3]Return book-----------------[4]Return\n");
    while(1){
        fflush(stdin);
        choice=getchar();
        fflush(stdin);
        switch(choice){
            case   '1':
                //��ʾ������Ϣ+�޸�
                self_manage(book_data,user);
                break;
            case   '2':
                //����
                borrow_book(book_data,user);
                break;
            case   '3':
                //����
                return_book(book_data,user);
                break;
            case   '4':
                //������һ��
                system("cls");
                return;
            default:
                system("cls");
                printf("Please enter again:\n");
                break;
        }
        printf("\t\t\t[1]Manage personal info---[2]Borrow book\n"
               "\t\t\t[3]Return book-----------------[4]Return\n");
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
        printf("Book_id:%d\n", user->book_id[i]);
        //display(book_id)չʾ�鼮��Ϣ
        display_book_code(user->book_id[i], book_data);
    }
    while (1) {
        if (exit_flag != 1) {
            printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�\n[1]ͼ�鿨����\n[2]��Ա����\n[3]��Ա�Ա�\n[4]������һ���˵�\n");
            fflush(stdin);
            option = getchar();
            fflush(stdin);
            switch (option) {
                case '1': {
                    printf("Enter new password:");//���������и�ȷ�ϵĹ��̰�
                    gets(user->password);
                    fflush(stdin);
                    break;
                }
                case '2': {
                    printf("Enter new name:");
                    gets(user->name);
                    fflush(stdin);
                    break;
                }
                case '3': {
                    printf("Enter new sex([0]Male[1]Female):");
                    scanf("%d", &user->sex);
                    fflush(stdin);
                    break;
                }
                case '4': {
                    system("cls");
                    return;
                }
                default:
                    printf("Input Error!Please Enter again:");
                    break;
            }
        }
        //��ʾ�û���Ϣ
        system("cls");
        penalty(book_data,user);
        display_person_pointer(user);
        for (int i = 0; i < borrow_quantity; ++i) {
            if(i==0)printf("\t\t\t--------Book borrowed--------\n");
            printf("Book_id:%d\n", user->book_id[i]);
            display_book_code(user->book_id[i], book_data);
        }
        //�����ж�
        if (exit_flag == 1)printf("Input error, please enter again:");
        exit_flag = 0;
        //ѯ���Ƿ����
        printf("whether to continue or not�� [1]Yes  [0]No\n");
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

//������㺯��������ʱ��һ��0.2Ԫ
void penalty(book_list *book_data,person *user){
    int         borrow_quantity=user->borrow_quantity;
    float       penalty=0;
    book        *borrowed_book=NULL;
    time_t      now,diff;
    now=time(NULL);
    for (int i=0;i<borrow_quantity;++i){
        borrowed_book=search_book_pointer(user->book_id[i],book_data);
        diff=(now-(borrowed_book->borrow_time+5097600));//��������ʱ����Ӧ��ʱ���ֵ
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
            printf("You can't borrow book because you have borrowed over 10 books or you have penalty to pay!\n");
            return;
        }
        else{
            printf("Enter the code of the book you want to borrow:\n");
            scanf("%d",&code);
            fflush(stdin);
            current_book = search_book_pointer(code,book_data);
            display_book_pointer(current_book);
            printf("Is it the book you want to borrow? Press 1 to continue, another key to abort:\n");
            choice=getchar();
            fflush(stdin);
            if(choice!='1'){
                system("cls");
                printf("Borrow aborted!\n");
                return;
            }
            if(current_book!=NULL){
               if(current_book->person_id_number==-1){
                   user->borrow_quantity++;
                   user->book_id[user->borrow_quantity]=code;
                   current_book->person_id_number=user->id_number;
                   current_book->borrow_time=time(NULL);
                   book_data->book_borrowed++;
                   printf("Book has been borrowed.\n");
               }
               else if(current_book->person_id_number!=-1){
                   printf("Sorry the book has been borrowed.\n");
               }
            }
            else {
                printf("Book not Found!\n");
            }
            printf("Whether to continue or not?Enter 1 to Borrow another book, enter something else to exit.\n");
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
            printf("Enter the code of the book you want to return:\n");
           scanf("%d",&code);
            fflush(stdin);
           current_book=search_book_pointer(code,book_data);
           if(current_book!=NULL&&current_book->person_id_number==user->id_number){
                //����Ԫ�أ������Ԫ�ش������ĳһ���ط��ҵ�
                for(i=0;i<borrow_quantity;++i){
                   if(user->book_id[i]==code){
                       user->book_id[i]=0;
                       break;
                   }
                }
                //�ҵ���Ѻ�һ��Ԫ����ǰ�ƶ�
                for(;i<borrow_quantity-1;++i){
                     if((i+1)<borrow_quantity){
                        user->book_id[i]=user->book_id[i+1];
                     }
                     else break;
                }
                user->borrow_quantity--;
                current_book->person_id_number=-1;
                book_data->book_borrowed--;
           }
           else if(current_book==NULL){
               printf("Book not found!\nEnter anything to continue:\n");
               getchar();
               fflush(stdin);
           }
           else {
               printf("Book can't be returned by you!\nEnter anything to continue:\n");
               getchar();
               fflush(stdin);
           }
            printf("Whether to continue or not?Enter 1 to return another book, enter something else to exit.\n");
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
        printf("You have no book to return!\nEnter anything to return menu.\n");
        getchar();
        fflush(stdin);
        return;
    }
}
