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
        printf("��ӭʹ������ϵͳ!\n"
               "�������һ���ؼ���ģ����ѯ�鼮��Ҳ����������һ���ؼ��ʺ󲻼ӿո�ӡ�|�������ٲ��ӿո����\n���¹ؼ������ɸѡָ���鼮��ÿ��ؼ���ֻ����һ��֮��Ҫ�пո�:\n"
               "author_name=��Ҫ������������\n"
               "book_name=��Ҫ����������\n"
               "code=��Ҫ����������\n"
               "press=��Ҫ�����ĳ�����\n"
               "borrowed=-1��ɸѡ�����ߵ���\n"
               "�������10��ؼ��ʣ���������Ҫ�����Ĺؼ���:\n");
        gets(search);
        fflush(stdin);
        format_keyword=strrchr(search,'|')+1;//Ѱ��|����һ��λ�ã����û����ΪNULL
        strncpy(search_normal_keywords,search,(strlen(search)-strlen(format_keyword))*sizeof(char));
        printf("%s\n%s",search_normal_keywords,format_keyword);//������ͨ�ؼ��ʺ���ʽ�ؼ���
        getchar();
        fflush(stdin);
        while(current_book!=NULL){
            sprintf(book_keyword,"author_name=%s book_name=%s borrowed=%d code=%d press=%s",current_book->author_name,current_book->book_name,current_book->person_id_number,current_book->code,current_book->press);
            if(strstr)

        }
        /*
         *
        sprintf(bala)
        if���Ӵ�
        bp[size]=b_p
        size++
        ��������
                (����������ҵ��Ӵ�ֱ�������)

        ���Ƿ����
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
    printf("�û���Ϣ:\n"
           "|ID:%-10d\n|����:%-10s\n",user->id_number,user->name);
    printf("|����:%-12s\n",user->password);
    if(user->sex==male)printf("|�Ա�:����  \n");
    else if(user->sex==female)printf("|�Ա�:Ů��\n");
    else printf("�Ա�:δ֪\n");
    if(user->prop==prop_reader)printf("|����:����\n");
    else if(user->prop==prop_administrator)printf("|����:����Ա");
    else printf("|����:δ֪");
    printf("|����:%.2f\n",user->penalty);
    printf("|�ѽ��鼮����:%-3d\n\n",user->borrow_quantity);
}

void display_book_pointer(book *p_book) {
    time_t now, borrow_time, return_time;
    printf("|����:%s\n|����:%-20s\n|������:%-20s\n", p_book->book_name, p_book->author_name, p_book->press);
    printf("|����:");
    switch (p_book->field) {
        case science:
            printf("��ѧ");
            break;
        case literature:
            printf("��ѧ");
            break;
        case education:
            printf("����");
            break;
        case art:
            printf("����");
            break;
        case life:
            printf("����");
            break;
        default:
            printf("δ֪");
            break;
    }
    printf("\n|�۸�:%6.2f\n\n", p_book->price);
    if (p_book->person_id_number == -1)
        return;
    else {
        printf("������:%d\n\n", p_book->person_id_number);
        now = time(NULL);
        borrow_time = p_book->borrow_time;
        return_time = p_book->borrow_time + 5184000;//2���µ�������2678400�ʣ�time_t������ʵ��long���
        printf("��ǰʱ��:%s\n", ctime(&now));
        printf("����ʱ��:%s\n", ctime(&borrow_time));
        printf("�涨����ʱ��:%s\n", ctime(&return_time));
    }
}

void display_book_code(int code, book_list *book_data){
    book        *p_book=search_book_pointer(code,book_data);
    if(p_book==NULL)
        printf("�޷��ҵ�����!\n");
    else
        display_book_pointer(p_book);
}

//����ָ�������Ӧ�Ľڵ�
//�п��ܷ���NULL
book *search_book_pointer(int code,book_list *book_data){
    book *book_current=book_data->head;
    if(book_current==NULL)return book_current;
    while(book_current->code!=code){
        book_current=book_current->next;
        if(book_current==NULL)return book_current;
    }
    return book_current;
}

//����ָ�����˶�Ӧ�Ľڵ�
//�п��ܷ���NULL
person *search_person_pointer(int id,person_list *person_data) {
    person *person_current = person_data->head;
    if (person_current == NULL)return person_current;
    while (person_current->id_number != id) {
        person_current = person_current->next;
        if (person_current == NULL)return person_current;
    }
    return person_current;
}

