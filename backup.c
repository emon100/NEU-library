#include "lib.h"

//
// Created by emon100 on 2019/3/20 0020.
//
//TODO:加入备份书的功能
//TODO:void recovery();

void file_io(book_list *book_data,person_list *person_data){
    char    option;
    system("cls");
    fflush(stdin);
    option=getchar();
    fflush(stdin);
    printf("[1]Backup------[2]Recovery\n"
           "[3]Return\n");
    while(1){
        switch (option){
            case '1':
                backup(book_data,person_data);
                break;
            case '2':
                //recovery(book_data,person_data);
                break;
            case '3':
                return;
            default :
                printf("Please enter again!\n");
                break;
        }
    }

}
void backup(book_list *book_data,person_list *person_data){
    char    option;
    system("cls");
    printf("Backup all infomation.Whether to continue or not?\nPress 1 to continue:\n");
    fflush(stdin);
    option=getchar();
    fflush(stdin);
    if(option=='1') {
        printf("正在备份人员信息...\n");
        person_backup(person_data);
    }
    else return;
}

//void recovery()
