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
    admin->head->next->sex=male;
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
    time_t      timer,test_t;//当前时间,测试时间
    struct tm   *test_time;
    //对时间进行操作
    timer=time(NULL);
    test_time=localtime(&timer);
    test_time->tm_mday=22;
    test_t=mktime(test_time);

    //对书进行操作
    book_data->size=4;
    book_data->book_borrowed=2;
    book_data->code=5;
    memset(book_data->book_size_field,0, sizeof(int)*(life+1));
    book_data->book_size_field[science]=2;
    book_data->book_size_field[art]=2;
    head->code=1;
    head->person_id_number=101;
    strcpy(head->book_name,"book1");
    head->price=49.99;
    strcpy(head->author_name,"WW");
    strcpy(head->press,"People's press");
    head->field=science;
    head->borrow_time=timer;
    head->next=next=(book *)malloc(sizeof(book));
    next->code=2;
    next->person_id_number=100;
    strcpy(next->book_name,"book2");
    next->price=29.99;
    next->field=art;
    strcpy(next->press,"First press");
    strcpy(next->author_name,"XX");
    next->next=(book *)malloc(sizeof(book));
    next->borrow_time=test_t;
    next=next->next;
    next->code=3;
    next->person_id_number=-1;
    strcpy(next->book_name,"book3");
    next->price=19.99;
    next->field=art;
    strcpy(next->press,"People's press");
    strcpy(next->author_name,"YY");
    next->next=(book *)malloc(sizeof(book));
    next=next->next;
    next->code=4;
    next->person_id_number=-1;
    strcpy(next->book_name,"book4");
    next->price=9.99;
    next->field=science;
    strcpy(next->press,"Second press");
    strcpy(next->author_name,"ZZ");
    next->next=NULL;
    book_data->tail=next;
}
