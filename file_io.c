#include "lib.h"

//
// Created by emon100 on 2019/3/20 0020.
//

void file_io(book_list *book_data,person_list *person_data){
    int     exit_flag=0;
    int option;
    system("cls");
    printf("[1]备份\n"
           "[2]还原\n"
           "[3]返回上级菜单\n");
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
                printf("请重新输入!\n");
                break;
        }
        if(exit_flag==1){
            system("cls");
            break;
        }
        printf("[1]备份\n"
               "[2]还原\n"
               "[3]返回上级菜单\n");
        fflush(stdin);
        option=getchar();
        fflush(stdin);
    }
}

void backup(book_list *book_data,person_list *person_data){
    int option;
    system("cls");
    printf("备份所有信息.是否要继续?\n输入 1 以继续 , 输入其他内容已取消此次操作:\n");
    fflush(stdin);
    option=getchar();
    fflush(stdin);
    if(option=='1') {
        printf("正在备份人员信息...\n");
        person_backup(person_data);
        printf("正在备份书本信息...\n");
        book_backup(book_data);
    }
}

void recovery(book_list *book_data,person_list *person_data){
    int option;
    system("cls");
    printf("还原所有信息.是否要继续?\n输入 1 以继续 , 输入其他内容已取消此次操作:\n");
    fflush(stdin);
    option=getchar();
    fflush(stdin);
    if(option=='1') {
        printf("正在恢复人员信息...\n");
        person_recovery(person_data);
        printf("正在恢复书本信息...\n");
        book_recovery(book_data);
    }
}
