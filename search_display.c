//
// Created by emon100 on 2019/3/21 0021.
//
#include "lib.h"
/*
void search_book(book_list *book_data){
        int size=0;
        book book_pointers[50];
        book current_book=book_data->head;
        char keyword[360];
        char search[100];
        while(1){
            size=0
            print(enter key bala)
            size=0
            gets(search)
            while()遍历book_current
            sprintf(bala)
            if找子串
            bp[size]=b_p
            size++
            遍历结束
                    (或者如果能找到子串直接输出吧)

            问是否继续
            continue
            break:
        }
}

void search_user(person_list *book_data){
    ;
}
 */

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
        default:
            printf("Error");
            break;
    }
    printf("\n|Price:%6.2f\n\n",p_book->price);
    if(p_book->person_id_number==-1)
        return;
    else{
        printf("Who borrowed:%d\n",p_book->person_id_number);
        now=time(NULL);
        borrow_time=p_book->borrow_time;
        return_time=p_book->borrow_time+5184000;//2个月的秒数是2678400故，time_t类型其实和long差不多
        printf("Now time:%s\n",ctime(&now));
        printf("Borrow time:%s\n",ctime(&borrow_time));
        printf("Should return before:%s\n",ctime(&return_time));
    }

void display_book_code(int code, book_list *book_data){
    book        *p_book=search_book_pointer(code,book_data);
    if(p_book==NULL)
        printf("Book not found!\n");
    else
        display_book_pointer(p_book);
}

//搜索指定的书对应的节点
//有可能返回NULL
book *search_book_pointer(int code,book_list *book_data){
    book *book_current=book_data->head;
    if(book_current==NULL)return book_current;
    while(book_current->code!=code){
        book_current=book_current->next;
        if(book_current==NULL)return book_current;
    }
    return book_current;
}

//搜索指定的人对应的节点
//有可能返回NULL
person *search_person_pointer(int id,person_list *person_data){
    person *person_current=person_data->head;
    if(person_current==NULL)return person_current;
    while(person_current->id_number!=id){
        person_current=person_current->next;
        if(person_current==NULL)return person_current;
    }
    return person_current;
}
