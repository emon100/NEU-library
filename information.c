//
// Created by emon100 on 2019/3/12 0012.
//
#include "lib.h"
//读者查看统计的函数
void information_reader(book_list *book_data,person_list *person_data){
    char        choice;
    system("cls");
    printf("information_reader\n");//记得删掉
    printf("\t\t\t*Welcome!--------------------------------*\n"
           "\t\t\t*[1]Check statistics-------[2]Search Book*\n"
           "\t\t\t*[3]Return-------------------------------*\n");
    //菜单
    fsh();
    while(choice=getchar()){
        fsh();
        switch(choice){
            case  '1':
                printf("Total book--science--literature--education--------art--------life\n");
                printf("%5d",book_data->size);
                for(int i=science;i<=life;i++)printf("%12d",book_data->book_size_field[i]);
                printf("\n");
                printf("Press any key to continue:\n");
                getchar();
                fsh();//吃回车
                system("cls");
                break;
            case  '2':
                printf("search book\n");
                break;
            case  '3':
                system("cls");
                return;
            default:
                system("cls");
                printf("Please enter again!:\n");
                break;
        }
        printf("\t\t\t*Welcome!--------------------------------*\n"
               "\t\t\t*[1]Check statistics-------[2]Search Book*\n"
               "\t\t\t*[3]Return-------------------------------*\n");
    }
}
//管理员查看统计的函数
void information_admin(book_list *book_data,person_list *person_data) {
    char choice;
    system("cls");
    printf("information_admin\n");//记得删掉
    printf("\t\t\t*Welcome!--------------------------------*\n"
           "\t\t\t*[1]Check statistics-------[2]Search Book*\n"
           "\t\t\t*[3]Return-------------------------------*\n");
    fsh();
    //下面都是菜单
    while (choice = getchar()) {
        fsh();
        switch (choice) {
            case '1':
                printf("Total book--science--literature--education--------art--------life\n");
                printf("%5d", book_data->size);
                for (int i = science; i <= life; i++)printf("%12d", book_data->book_size_field[i]);
                printf("\n");
                printf("Total User---Admins---Total readers---male readers---Female readers\n");
                printf("%5d%11d%13d%13d%13d\n",person_data->size,person_data->admin_size,person_data->size-person_data->admin_size,person_data->male_reader_size,person_data->size-person_data->admin_size-person_data->male_reader_size);
                printf("Press any key to continue:\n");
                getchar();
                fsh();
                system("cls");
                break;
            case '2':
                printf("search book\n");
                break;
            case '3':
                system("cls");
                return;
            default:
                system("cls");
                printf("Please enter again!:\n");
                break;
        }
        printf("\t\t\t*Welcome!--------------------------------*\n"
               "\t\t\t*[1]Check statistics-------[2]Search Book*\n"
               "\t\t\t*[3]Return-------------------------------*\n");
    }
}
