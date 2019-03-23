#include "lib.h"

//
// Created by emon100 on 2019/3/20 0020.
//

void file_io(book_list *book_data,person_list *person_data){
    int     exit_flag=0;
    int option;
    system("cls");
    printf("[1]����\n"
           "[2]��ԭ\n"
           "[3]�����ϼ��˵�\n");
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
                printf("����������!\n");
                break;
        }
        if(exit_flag==1){
            system("cls");
            break;
        }
        printf("[1]����\n"
               "[2]��ԭ\n"
               "[3]�����ϼ��˵�\n");
        fflush(stdin);
        option=getchar();
        fflush(stdin);
    }
}

void backup(book_list *book_data,person_list *person_data){
    int option;
    system("cls");
    printf("����������Ϣ.�Ƿ�Ҫ����?\n���� 1 �Լ��� , ��������������ȡ���˴β���:\n");
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
    int option;
    system("cls");
    printf("��ԭ������Ϣ.�Ƿ�Ҫ����?\n���� 1 �Լ��� , ��������������ȡ���˴β���:\n");
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
