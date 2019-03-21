//
// Created by emon100 on 2019/3/21 0021.
//
#include "lib.h"

void sort(book_list *book_data,person_list *person_data) {
    int choice;
    system("cls");
    fflush(stdin);
    printf("\t\t\t*----------Welcome!-----------*\n"
           "\t\t\t*[1]Sort Users by id number---*"
           "\t\t\t*[2]Sort Users by name--------*"
           "\t\t\t*[3]Sort Books by code--------*"
           "\t\t\t*[4]Sort Books by name--------*"
           "\t\t\t*[5]Sort Books by price--------*"
           "\t\t\t*[0]Return--------------------*\n");
    while (choice = getchar()) {
        fflush(stdin);//³Ô»Ø³µ
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
                printf("Book order by code");
                break;
            case '4':
                system("cls");
                printf("Book order by name");
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
        printf("\t\t\t*----------Welcome!-----------*\n"
               "\t\t\t*[1]Sort Users by id number---*"
               "\t\t\t*[2]Sort Users by name--------*"
               "\t\t\t*[3]Sort Books by code--------*"
               "\t\t\t*[4]Sort Books by name--------*"
               "\t\t\t*[5]Sort Books by price--------*"
               "\t\t\t*[0]Return--------------------*\n");
        fflush(stdin);
    }
}

