//
// Created by emon100 on 2019/3/21 0021.
//
#include "lib.h"

void sort(book_list *book_data,person_list *person_data) {
    int choice;
    system("cls");
    fflush(stdin);
    printf("\t\t\t��ӭʹ����Ϣ����ϵͳ!\n"
           "\t\t\t[1]���û��˺�����\n"
           "\t\t\t[2]���û���������\n"
           "\t\t\t[3]���鼮��������\n"
           "\t\t\t[4]���鼮��������\n"
           "\t\t\t[5]���鼮�۸�����\n"
           "\t\t\t[0]�����ϼ��˵�\n");
    while (choice = getchar()) {
        fflush(stdin);//�Իس�
        switch (choice) {
            case '1':
                system("cls");
                person_order_in_id_number(person_data);
                break;
            case '2':
                system("cls");
                person_order_in_name(person_data);
                break;
            case '3':
                system("cls");
                book_order_in_code(book_data);
                break;
            case '4':
                system("cls");
                book_order_in_name(book_data);
                break;
            case '5':
                system("cls");
                book_order_in_price(book_data);
                break;
            case '0':
                system("cls");
                return;
            default:
                system("cls");

        }
        printf("\t\t\t��ӭʹ����Ϣ����ϵͳ!\n"
               "\t\t\t[1]���û��˺�����\n"
               "\t\t\t[2]���û���������\n"
               "\t\t\t[3]���鼮��������\n"
               "\t\t\t[4]���鼮��������\n"
               "\t\t\t[5]���鼮�۸�����\n"
               "\t\t\t[0]�����ϼ��˵�\n");
        fflush(stdin);
    }
}

