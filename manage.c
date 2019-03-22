//
// Created by emon100 on 2019/3/12 0012.
//TODO:book_delete()
#include "lib.h"

void manage(book_list *book_data,person_list *person_data) {
    int choice;
    system("cls");
    fflush(stdin);
    printf("\t\t\t欢迎来到管理系统!\n"
           "\t\t\t[1]编辑用户信息\n"
           "\t\t\t[2]添加新的用户\n"
           "\t\t\t[3]删除用户\n"
           "\t\t\t[4]编辑书籍信息\n"
           "\t\t\t[5]添加书籍\n"
           "\t\t\t[6]删除书籍\n"
           "\t\t\t[7]备份和还原\n"
           "\t\t\t[8]排序\n"
           "\t\t\t[0]返回上级菜单\n");
    while (choice = getchar()) {
        fflush(stdin);//吃回车
        switch (choice) {
            case '1':
                system("cls");
                person_edit(person_data);
                break;
            case '2':
                system("cls");
                person_insert(person_data);
                break;
            case '3':
                system("cls");
                person_delete(person_data);
                break;
            case '4':
                system("cls");
                book_edit(book_data);
                break;
            case '5':
                system("cls");
                book_insert(book_data);
                break;
            case '6':
                system("cls");
                book_delete(book_data);
                break;
            case '7':
                system("cls");
                file_io(book_data,person_data);
                break;
            case '8':
                system("cls");
                sort(book_data,person_data);
                break;
            case '0':
                system("cls");
                return;
            default:
                system("cls");

        }
        printf("\t\t\t欢迎来到管理系统!\n"
               "\t\t\t[1]编辑用户信息\n"
               "\t\t\t[2]添加新的用户\n"
               "\t\t\t[3]删除用户\n"
               "\t\t\t[4]编辑书籍信息\n"
               "\t\t\t[5]添加书籍\n"
               "\t\t\t[6]删除书籍\n"
               "\t\t\t[7]备份和还原\n"
               "\t\t\t[8]排序\n"
               "\t\t\t[0]返回上级菜单\n");
        fflush(stdin);
    }
}

