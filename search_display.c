//
// Created by emon100 on 2019/3/21 0021.
//
#include "lib.h"
void search_book(book_list *book_data){
    system("cls");
    int     size=0;
    book    book_pointers[10];
    book    *current_book=book_data->head;
    char    book_keyword[360];
    char    search[1000];
    char    search_format_keywords[10][210];
    char    search_normal_keywords[210];
    char    *format_keyword;
    while(1){
        fflush(stdin);
        size=0;
        printf("欢迎使用搜索系统!\n"
               "你可以用一个关键词模糊查询书籍，也可以在输完一个关键词后不加空格加“|”符号再不加空格搭配\n以下关键词语句筛选指定书籍，每组关键词只能输一遍之间要有空格:\n"
               "author_name=你要搜索的作者名\n"
               "book_name=你要搜索的书名\n"
               "code=你要搜索的条码\n"
               "press=你要搜索的出版社\n"
               "borrowed=-1来筛选被借走的书\n"
               "最多输入10组关键词，请输入你要搜索的关键词:\n");
        gets(search);
        fflush(stdin);
        format_keyword=strrchr(search,'|')+1;//寻找|的下一个位置，如果没有则为NULL
        strncpy(search_normal_keywords,search,(strlen(search)-strlen(format_keyword))*sizeof(char));
        printf("%s\n%s",search_normal_keywords,format_keyword);//测试普通关键词和形式关键词
        getchar();
        fflush(stdin);
        while(current_book!=NULL){
            sprintf(book_keyword,"author_name=%s book_name=%s borrowed=%d code=%d press=%s",current_book->author_name,current_book->book_name,current_book->person_id_number,current_book->code,current_book->press);
            if(strstr)

        }
        /*
         *
        sprintf(bala)
        if找子串
        bp[size]=b_p
        size++
        遍历结束
                (或者如果能找到子串直接输出吧)

        问是否继续
        continue
        break:
         */
    }
}

/*
void search_user(person_list *book_data){
    ;
}
 */

void display_person_pointer(person *user){
    printf("用户信息:\n"
           "|ID:%-10d\n|姓名:%-10s\n",user->id_number,user->name);
    printf("|密码:%-12s\n",user->password);
    if(user->sex==male)printf("|性别:男性  \n");
    else if(user->sex==female)printf("|性别:女性\n");
    else printf("性别:未知\n");
    if(user->prop==prop_reader)printf("|属性:读者\n");
    else if(user->prop==prop_administrator)printf("|属性:管理员");
    else printf("|属性:未知");
    printf("|罚金:%.2f\n",user->penalty);
    printf("|已借书籍数量:%-3d\n\n",user->borrow_quantity);
}

void display_book_pointer(book *p_book) {
    time_t now, borrow_time, return_time;
    printf("|标题:%s\n|作者:%-20s\n|出版社:%-20s\n", p_book->book_name, p_book->author_name, p_book->press);
    printf("|领域:");
    switch (p_book->field) {
        case science:
            printf("科学");
            break;
        case literature:
            printf("文学");
            break;
        case education:
            printf("教育");
            break;
        case art:
            printf("艺术");
            break;
        case life:
            printf("生活");
            break;
        default:
            printf("未知");
            break;
    }
    printf("\n|价格:%6.2f\n\n", p_book->price);
    if (p_book->person_id_number == -1)
        return;
    else {
        printf("借书者:%d\n\n", p_book->person_id_number);
        now = time(NULL);
        borrow_time = p_book->borrow_time;
        return_time = p_book->borrow_time + 5184000;//2个月的秒数是2678400故，time_t类型其实和long差不多
        printf("当前时间:%s\n", ctime(&now));
        printf("结束时间:%s\n", ctime(&borrow_time));
        printf("规定还书时间:%s\n", ctime(&return_time));
    }
}

void display_book_code(int code, book_list *book_data){
    book        *p_book=search_book_pointer(code,book_data);
    if(p_book==NULL)
        printf("无法找到此书!\n");
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
person *search_person_pointer(int id,person_list *person_data) {
    person *person_current = person_data->head;
    if (person_current == NULL)return person_current;
    while (person_current->id_number != id) {
        person_current = person_current->next;
        if (person_current == NULL)return person_current;
    }
    return person_current;
}

