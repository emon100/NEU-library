//
// Created by emon100 on 2019/3/8 0008.
//
#include "lib.h"


void admin_init(person_list *admin){
    person          *p1;
    admin->head=(person *)malloc(sizeof(person));
    admin->head->id_number=1;
    admin->head->sex=male;
    strcpy(admin->head->name,"admin");
    strcpy(admin->head->password,"pass");
    admin->head->prop=prop_administrator;
    admin->head->next=(person*)malloc(sizeof(person));
    admin->head->next->id_number=100;
    strcpy(admin->head->next->name,"emon");
    strcpy(admin->head->next->password,"123");
    admin->head->next->prop=prop_reader;
    admin->head->next->borrow_quantity=1;
    admin->head->next->book_id[0]=2;
    p1=admin->head->next->next=(person *)malloc(sizeof(person));
    p1->next=NULL;
    p1->id_number=101;
    p1->name="Eliz";
    p1->password="11";
    p1->prop=prop_reader;
    p1->borrow_quantity=1;
    p1->book_id[0]=1;
}

void book_test(book_list *book_data){
    book        *head=book_data->head=(book *)malloc(sizeof(book));
    book        *next;
    book_data->size=4;
    book_data->book_borrowed=2;
    book_data->code=4;
    head->code=1;
    head->book_name="book1";
    head->price=9.99;
    head->field=
}
