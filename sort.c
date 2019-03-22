//
// Created by emon100 on 2019/3/21 0021.
//
#include "lib.h"

void sort(book_list *book_data,person_list *person_data) {
    int choice;
    system("cls");
    fflush(stdin);
    printf("\t\t\t欢迎使用信息排序系统!\n"
           "\t\t\t[1]以用户账号排序\n"
           "\t\t\t[2]以用户姓名排序\n"
           "\t\t\t[3]以书籍编码排序\n"
           "\t\t\t[4]以书籍名称排序\n"
           "\t\t\t[5]以书籍价格排序\n"
           "\t\t\t[0]返回上级菜单\n");
    while (choice = getchar()) {
        fflush(stdin);//吃回车
        switch (choice) {
            case '1':
                system("cls");
                person_order_in_id_number(person_data);
                break;
            case '2':
                system("cls");
                person_order_in_name(person_data);
                break;
            case '3':
                system("cls");
                book_order_in_code(book_data);
                break;
            case '4':
                system("cls");
                book_order_in_name(book_data);
                break;
            case '5':
                system("cls");
                book_order_in_price(book_data);
                break;
            case '0':
                system("cls");
                return;
            default:
                system("cls");

        }
        printf("\t\t\t欢迎使用信息排序系统!\n"
               "\t\t\t[1]以用户账号排序\n"
               "\t\t\t[2]以用户姓名排序\n"
               "\t\t\t[3]以书籍编码排序\n"
               "\t\t\t[4]以书籍名称排序\n"
               "\t\t\t[5]以书籍价格排序\n"
               "\t\t\t[0]返回上级菜单\n");
        fflush(stdin);
    }
}

