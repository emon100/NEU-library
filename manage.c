//
// Created by emon100 on 2019/3/12 0012.
//
#include "lib.h"

void manage(book_list *book_data,person_list *person_data){
    int         user_id;
    system("cls");
    person_edit(person_data);
    printf("Press any key to continue:\n");
    getchar();
    fflush(stdin);
    system("cls");
}

