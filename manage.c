//
// Created by emon100 on 2019/3/12 0012.
//TODO:book_delete()
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
           "\t\t\t*[7]Backup and Recovery-------*\n"
           "\t\t\t*[8]Sort----------------------*\n"
           "\t\t\t*[0]Return--------------------*\n");
    while (choice = getchar()) {
        fflush(stdin);//�Իس�
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
        printf("\t\t\t*Welcome to management system!*\n"
               "\t\t\t*[1]Edit User's info----------*\n"
               "\t\t\t*[2]Add new User--------------*\n"
               "\t\t\t*[3]Delete User---------------*\n"
               "\t\t\t*[4]Edit book's info----------*\n"
               "\t\t\t*[5]Add book------------------*\n"
               "\t\t\t*[6]Delete book---------------*\n"
               "\t\t\t*[7]Backup and Recovery-------*\n"
               "\t\t\t*[8]Sort----------------------*\n"
               "\t\t\t*[0]Return--------------------*\n");
        fflush(stdin);
    }
}

