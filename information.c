//
// Created by emon100 on 2019/3/12 0012.
//
#include "lib.h"

void information_reader(book_list *book_data,person_list *book_list){
    char        choice;
    system("cls");
    printf("information_reader\n");
    printf("*Welcome!--------------------------------*\n"
           "*[1]Check statistics-------[2]Search Book*\n"
           "*[3]Return-------------------------------*\n");
    fsh();
    while(choice=getchar()){
        switch(choice){
            case  '1':
                printf("check statistics\n");break;
            case  '2':
                printf("search book\n");break;
            case  '3':
                return;
            default:
                break;
        }
        printf("*Welcome!--------------------------------*\n"
               "*[1]Check statistics-------[2]Search Book*\n"
               "*[3]Return-------------------------------*\n");
        fsh();
    }
}

void information_admin(book_list *book_data,person_list *book_list) {
    printf("information_admin\n");
}
