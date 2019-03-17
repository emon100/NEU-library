//
// Created by emon100 on 2019/3/8 0008.
//
#include "lib.h"


void admin_init(person_list *admin){
    person          *p1;
    admin->size=3;
    admin->admin_size=1;
    admin->male_reader_size=1;
    admin->id_number=102;
    admin->head=(person *)malloc(sizeof(person));
    admin->head->id_number=1;
    strcpy(admin->head->name,"admin");
    admin->head->sex=male;
    strcpy(admin->head->password,"pass");
    admin->head->prop=prop_administrator;
    admin->head->borrow_quantity=0;
    admin->head->penalty=0;
    admin->head->next=(person*)malloc(sizeof(person));
    admin->head->next->id_number=100;
    strcpy(admin->head->next->name,"emon");
    strcpy(admin->head->next->password,"123");
    admin->head->next->prop=prop_reader;
    admin->head->next->borrow_quantity=1;
    admin->head->next->book_id[0]=2;
    admin->head->next->penalty=1;
    p1=admin->tail=admin->head->next->next=(person *)malloc(sizeof(person));
    p1->next=NULL;
    p1->id_number=101;
    strcpy(p1->name,"Eliza");
    strcpy(p1->password,"11");
    p1->sex=female;
    p1->prop=prop_reader;
    p1->borrow_quantity=1;
    p1->book_id[0]=1;
    p1->penalty=0;
    admin->tail=p1;
}

void book_test(book_list *book_data){
    book        *head=book_data->head=(book *)malloc(sizeof(book));
    book        *next;
    book_data->size=4;
    book_data->book_borrowed=2;
    book_data->code=4;
    memset(book_data->book_size_field,0, sizeof(int)*(life+1));
    book_data->book_size_field[science]=2;
    book_data->book_size_field[art]=2;
    head->code=1;
    head->id_number=101;
    strcpy(head->book_name,"book1");
    head->price=9.99;
    strcpy(head->author_name,"WW");
    strcpy(head->press,"People's press");
    head->field=science;
    head->next=next=(book *)malloc(sizeof(book));
    next->code=2;
    next->id_number=100;
    strcpy(next->book_name,"book2");
    next->price=19.99;
    next->field=art;
    strcpy(next->press,"First press");
    strcpy(next->author_name,"XX");
    next->next=(book *)malloc(sizeof(book));
    next=next->next;
    next->code=3;
    next->id_number=-1;
    strcpy(next->book_name,"book3");
    next->price=29.99;
    next->field=art;
    strcpy(next->press,"People's press");
    strcpy(next->author_name,"YY");
    next->next=(book *)malloc(sizeof(book));
    next=next->next;
    next->code=4;
    next->id_number=-1;
    strcpy(next->book_name,"book4");
    next->price=49.99;
    next->field=science;
    strcpy(next->press,"Second press");
    strcpy(next->author_name,"ZZ");
    next->next=NULL;
}
