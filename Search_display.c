//
// Created by emon100 on 2019/3/21 0021.
//
#include "lib.h"

void display_person_pointer(person *user){
    printf("\nUser's infomation:\n"
           "ID:%-5d|Name:%-10s|",user->id_number,user->name);
    printf("password:%-12s|",user->password);
    if(user->sex==male)printf("Sex:Male  |\n");
    else if(user->sex==female)printf("Sex:Female|\n");
    else printf("Sex:Error\n");
    if(user->prop==prop_reader)printf("Property:Reader         |");
    else if(user->prop==prop_administrator)printf("Property:Administrator  |");
    else printf("Property:Error  |");
    printf("Penalty:%6.2f       |",user->penalty);
    printf("Book borrowed:%-3d\n\n",user->borrow_quantity);
}

void display_book_pointer(book *p_book){
    time_t      now,borrow_time,return_time;
    printf("|Title:%-30s\n|Author:%-20s\n|Press:%-20s\n",p_book->book_name,p_book->author_name,p_book->press);
    printf("|Field:");
    switch(p_book->field){
        case science:
            printf("Science");
            break;
        case literature:
            printf("Literature");
            break;
        case education:
            printf("Education");
            break;
        case art:
            printf("Art");
            break;
        case life:
            printf("Life");
            break;
    }
    printf("\n|Price:%6.2f\n\n",p_book->price);
    if(p_book->id_number==-1)
        return;
    else{
        now=time(NULL);
        borrow_time=p_book->borrow_time;
        return_time=p_book->borrow_time+5184000;//2个月的秒数是2678400故，time_t类型其实和long差不多
        printf("Now time:%s\n",ctime(&now));
        printf("Borrow time:%s\n",ctime(&borrow_time));
        printf("Should return before:%s\n",ctime(&return_time));
    }
}
void display_book_code(book_list *book_data, int book_id){
    book        *p_book=book_data->head;
    while(p_book->code!=book_id&&p_book!=NULL){
        p_book=p_book->next;
    }
    if(p_book==NULL)
        printf("Book not found!\n");
    else
        display_book_pointer(p_book);

}
