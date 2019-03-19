//
// Created by emon100 on 2019/3/12 0012.
//
#include "lib.h"

void manage(book_list *book_data,person_list *person_data) {
    int choice;
    system("cls");
    fflush(stdin);
    printf("\t\t\t*Welcome to management system!*\n"
           "\t\t\t*[1]Edit User's info----------*\n"
           "\t\t\t*[2]Add new User--------------*\n"
           "\t\t\t*[3]Delete User---------------*\n"
           "\t\t\t*[4]Edit book's info----------*\n"
           "\t\t\t*[5]Add book------------------*\n"
           "\t\t\t*[6]Delete book---------------*\n"
           "\t\t\t*[7]Return--------------------*\n");
    while (choice = getchar()) {
        fflush(stdin);//³Ô»Ø³µ
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
            case '7':
                system("cls");
                return;
            default:
                system("cls");

        }
        printf("\t\t\t*Welcome to management system!*\n"
               "\t\t\t*[1]Edit User's info----------*\n"
               "\t\t\t*[2]Add new User--------------*\n"
               "\t\t\t*[3]Delete User---------------*\n"
               "\t\t\t*[4]Edit book's info----------*\n"
               "\t\t\t*[5]Add book------------------*\n"
               "\t\t\t*[6]Delete book---------------*\n"
               "\t\t\t*[7]Return--------------------*\n");
    }
}

