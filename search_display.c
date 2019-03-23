//
// Created by emon100 on 2019/3/21 0021.
//
#include "lib.h"

void search_book(book_list *book_data) {
    system("cls");
    book *book_pointers[10] = {0};
    book *current_book;
    int flag[5] = {0};
    int count;
    int choice;
    char book_keywords[400];
    char search_blurred[200];

    int code;
    char name[100];
    char author[200];
    enum field field;
    while (1) {
        field=-1;
        current_book=book_data->head;
        memset(flag, 0, sizeof(int)*5);
        memset(search_blurred, 0, sizeof(char)*200);
        count = 0;
        system("cls");
        printf("��ӭʹ�ò���ϵͳ!\n��ѡ���ܣ�\n"
               "[1]ģ�����ҹ���\n[2]ɸѡ����\n[0]�˳�\n");
        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                printf("����ؼ���:\n");
                gets(search_blurred);
                strlwr(search_blurred);
                fflush(stdin);
                while (current_book != NULL) {
                    sprintf(book_keywords, "%d %s %s %s %d", current_book->code, strlwr(current_book->book_name),
                            strlwr(current_book->author_name), strlwr(current_book->press), current_book->person_id_number);
                    if (strstr(book_keywords,search_blurred) != NULL && count < 10) {
                        book_pointers[count] = current_book;
                        count++;
                    }
                    if(count==10)break;
                    current_book=current_book->next;
                }
                for (int i = 0; i < count; ++i) {
                    display_book_pointer(book_pointers[i]);
                }
                printf("��ѯ��ɣ��������������Լ���\n");
                getchar();
                fflush(stdin);
                break;
            case 2:
                printf("����0�Բ����鼮������ң������������ݼ���\n");
                if (getchar() == '0')flag[0] = 1;
                fflush(stdin);
                printf("����0�Բ����������ң������������ݼ���\n");
                if (getchar() == '0')flag[1] = 1;
                fflush(stdin);
                printf("����0�Բ������������ң������������ݼ���\n");
                if (getchar() == '0')flag[2] = 1;
                fflush(stdin);
                printf("����0�Բ���רҵ������ң������������ݼ���\n");
                if (getchar() == '0')flag[3] = 1;
                fflush(stdin);
                printf("����0����������������飬����������������������������ߵ���\n");
                if (getchar() == '0')flag[4] = 1;
                fflush(stdin);
                if (flag[0] == 0) {
                    printf("�������룺\n");
                    scanf("%d", &code);
                    fflush(stdin);
                    display_book_code(code,book_data);
                    break;
                }
                if (flag[1] == 0) {
                    printf("����������\n");
                    gets(name);
                    strlwr(name);
                    fflush(stdin);
                }
                if (flag[2] == 0) {
                    printf("�������ߣ�\n");
                    gets(author);
                    strlwr(author);
                    fflush(stdin);
                }
                if (flag[3] == 0) {
                    printf("����רҵ����\n[0]��ѧ[1]��ѧ[2]����[3]����[4]����\n");
                    scanf("%d", &field);
                    fflush(stdin);
                }
                    while (current_book != NULL) {
                        if (count < 10) {
                            if (strstr(strlwr(current_book->book_name),name) != NULL || flag[1]) {
                                if (strstr(strlwr(current_book->author_name),author) != NULL || flag[2]) {
                                    if (current_book->field == field || flag[3]) {
                                        if (current_book->person_id_number == -1 || flag[4]) {
                                            book_pointers[count] = current_book;
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                        else
                            break;
                        current_book = current_book->next;
                    }
                    if(count==0){
                        printf("û���ҵ�ָ���鼮\n");
                        break;
                    }
                    else {
                        for (int i = 0; i < count; i++) {
                            display_book_pointer(book_pointers[i]);
                        }
                    }
                printf("��ѯ��ɣ��������������Լ���\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case 0:
                system("cls");
                return;
            default:
                printf("�����������������:\n");
                break;
        }
        printf("�Ƿ������ѯ������1������������ȡ��\n");
        if(getchar()=='1'){
            fflush(stdin);
            system("cls");
            continue;
        }
        else {
            fflush(stdin);
            system("cls");
            break;
        }
    }
}

void search_user(person_list *person_data) {
    system("cls");
    person      *person_pointers[10] = {0};
    person      *current_person;
    int flag[5] = {0};
    int count;
    int choice;
    char user_keywords[400];
    char search_blurred[200];

    while (1) {
        current_person=person_data->head;
        memset(flag, 0, sizeof(int)*5);
        memset(search_blurred, 0, sizeof(char)*200);
        count = 0;
        system("cls");
        printf("��ӭʹ�ò���ϵͳ!\n��ѡ���ܣ�\n"
               "[1]ģ�����ҹ���\n[0]�˳�\n");
        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                printf("����ؼ���:\n");
                gets(search_blurred);
                strlwr(search_blurred);
                fflush(stdin);
                while (current_person != NULL) {
                    sprintf(user_keywords, "%d %s", current_person->id_number, strlwr(current_person->name));
                    if (strstr(user_keywords,search_blurred) != NULL && count < 10) {
                        person_pointers[count] = current_person;
                        count++;
                    }
                    if(count==10)break;
                    current_person=current_person->next;
                }
                for (int i = 0; i < count; ++i) {
                    display_person_pointer(person_pointers[i]);
                }
                printf("��ѯ��ɣ��������������Լ���\n");
                getchar();
                fflush(stdin);
                break;
            case 0:
                system("cls");
                return;
            default:
                printf("�����������������:\n");
                break;
        }
        printf("�Ƿ������ѯ������1������������ȡ��\n");
        if(getchar()=='1'){
            fflush(stdin);
            system("cls");
            continue;
        }
        else {
            fflush(stdin);
            system("cls");
            break;
        }
    }
}

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
    printf("|����:%d\n",p_book->code);
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
        printf("����ʱ��:%s\n", ctime(&borrow_time));
        printf("�涨����ʱ��:%s\n", ctime(&return_time));
        printf("��ǰʱ��:%s\n", ctime(&now));
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

