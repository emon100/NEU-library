//
// Created by emon100 on 2019/3/12 0012.
//TODO:book_delete()
#include "lib.h"

void manage(book_list *book_data,person_list *person_data) {
    int choice;
    system("cls");
    fflush(stdin);
    printf("\t\t\t��ӭ��������ϵͳ!\n"
           "\t\t\t[1]�༭�û���Ϣ\n"
           "\t\t\t[2]����µ��û�\n"
           "\t\t\t[3]ɾ���û�\n"
           "\t\t\t[4]�༭�鼮��Ϣ\n"
           "\t\t\t[5]����鼮\n"
           "\t\t\t[6]ɾ���鼮\n"
           "\t\t\t[7]���ݺͻ�ԭ\n"
           "\t\t\t[8]����\n"
           "\t\t\t[0]�����ϼ��˵�\n");
    while (choice = getchar()) {
        fflush(stdin);//�Իس�
        switch (choice) {
            case '1':
                system("cls");
                person_edit(person_data);
                break;
            case '2':
                system("cls");
                person_insert(person_data);
                break;
            case '3':
                system("cls");
                person_delete(person_data);
                break;
            case '4':
                system("cls");
                book_edit(book_data);
                break;
            case '5':
                system("cls");
                book_insert(book_data);
                break;
            case '6':
                system("cls");
                book_delete(book_data);
                break;
            case '7':
                system("cls");
                file_io(book_data,person_data);
                break;
            case '8':
                system("cls");
                sort(book_data,person_data);
                break;
            case '0':
                system("cls");
                return;
            default:
                system("cls");

        }
        printf("\t\t\t��ӭ��������ϵͳ!\n"
               "\t\t\t[1]�༭�û���Ϣ\n"
               "\t\t\t[2]����µ��û�\n"
               "\t\t\t[3]ɾ���û�\n"
               "\t\t\t[4]�༭�鼮��Ϣ\n"
               "\t\t\t[5]����鼮\n"
               "\t\t\t[6]ɾ���鼮\n"
               "\t\t\t[7]���ݺͻ�ԭ\n"
               "\t\t\t[8]����\n"
               "\t\t\t[0]�����ϼ��˵�\n");
        fflush(stdin);
    }
}

