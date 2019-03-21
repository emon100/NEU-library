#include "lib.h"

//
// Created by emon100 on 2019/3/20 0020.
//
//TODO:��ı��ݻ�ԭ

void file_io(book_list *book_data,person_list *person_data){
    int     exit_flag=0;
    char    option;
    system("cls");
    printf("[1]Backup------[2]Recovery\n"
           "[3]Return\n");
    fflush(stdin);
    option=getchar();
    fflush(stdin);
    while(1){
        switch (option){
            case '1':
                backup(book_data,person_data);
                break;
            case '2':
                recovery(book_data,person_data);
                break;
            case '3':
                exit_flag=1;
                break;
            default :
                printf("Please enter again!\n");
                break;
        }
        if(exit_flag==1){
            system("cls");
            break;
        }
        printf("[1]Backup------[2]Recovery\n"
               "[3]Return\n");
        fflush(stdin);
        option=getchar();
        fflush(stdin);
    }
}

void backup(book_list *book_data,person_list *person_data){
    char    option;
    system("cls");
    printf("Backup all information.Whether to continue or not?\nPress 1 to continue, another key to abort:\n");
    fflush(stdin);
    option=getchar();
    fflush(stdin);
    if(option=='1') {
        printf("���ڱ�����Ա��Ϣ...\n");
        person_backup(person_data);
        printf("���ڱ����鱾��Ϣ...\n");
        book_backup(book_data);
    }
}

void recovery(book_list *book_data,person_list *person_data){
    char    option;
    system("cls");
    printf("Recovery all information.Whether to continue or not?\nPress 1 to continue, another key to abort:\n");
    fflush(stdin);
    option=getchar();
    fflush(stdin);
    if(option=='1') {
        printf("���ڻָ���Ա��Ϣ...\n");
        person_recovery(person_data);
        printf("���ڻָ��鱾��Ϣ...\n");
        book_recovery(book_data);
    }
}
