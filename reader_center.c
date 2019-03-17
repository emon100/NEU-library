//
// Created by 王一蒙 on 2019/3/12 0012.
//
#include "lib.h"

//借还书功能函数

void  reader_center(book_list *book_data,person *current_user){
    //printf("reader_center\n");
    //printf("Press any key to continue:\n");
    char        choice;
    printf("[1]Manage personal info---[4]Return");
    while(choice=getchar()){
        fflush(stdin);
        switch(choice){
            case   '1':
                //显示个人信息+修改
                self_manage(current_user);
                break;
            case   '2':
                //借书
                break;
            case   '3':
                //还书
                break;
            case   '4':
                //返回上一层
                system("cls");
                return;
        }
        printf("[1]manage [4]Return");
    }
    getchar();
    fflush(stdin);
    system("cls");
}

void self_manage(person *current_user){
    int             borrow_quantity=current_user->borrow_quantity;
    system("cls");
    display_person(current_user);
    for (int i = 0; i < borrow_quantity; ++i) {
        printf("book_id:%d\n",current_user->book_id[i]);
        //display(book_id)展示书籍信息
    }
    printf("Press any key to continue...");
    getchar();
    fflush(stdin);
}

void display_person(person *current_user){
    printf("\nUser's infomation:\n"
           "ID:%-5d|Name:%-10s|",current_user->id_number,current_user->name);
    printf("password:%-12s|",current_user->password);
    if(current_user->sex==male)printf("Sex:Male  |\n");
    else printf("Sex:Female|\n");
    if(current_user->prop==prop_reader)printf("Property:Reader         |");
    else printf("Property:Administrator  |");
    printf("Penalty:%6.2f       |",current_user->penalty);
    printf("Book borrowed:%-3d\n\n",current_user->borrow_quantity);
}
