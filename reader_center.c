//
// Created by ��һ�� on 2019/3/12 0012.
//
#include "lib.h"

//�軹�鹦�ܺ���

void  reader_center(book_list *book_data,person *user){
    //printf("reader_center\n");
    //printf("Press any key to continue:\n");
    int choice;
    printf("\t\t\t[1]Manage personal info---[2]Borrow book\n"
           "\t\t\t[3]Return book-----------------[4]Return\n");
    while(1){
        fflush(stdin);
        choice=getchar();
        fflush(stdin);
        switch(choice){
            case   '1':
                //��ʾ������Ϣ+�޸�
                self_manage(book_data,user);
                break;
            case   '2':
                //����
                borrow_book(book_data,user);
                break;
            case   '3':
                //����
                return_book(book_data,user);
                break;
            case   '4':
                //������һ��
                system("cls");
                return;
            default:
                system("cls");
                printf("Please enter again:\n");
                break;
        }
        printf("\t\t\t[1]Manage personal info---[2]Borrow book\n"
               "\t\t\t[3]Return book-----------------[4]Return\n");
    }
}

void self_manage(book_list *book_data,person *user) {
    int borrow_quantity = user->borrow_quantity;
    int exit_flag = 0;
    int option;
    system("cls");
    display_person_pointer(user);
    for (int i = 0; i < borrow_quantity; ++i) {
        printf("Book_id:%d\n", user->book_id[i]);
        //display(book_id)չʾ�鼮��Ϣ
        display_book_code(book_data, user->book_id[i]);
    }
    while (1) {
        if (exit_flag != 1) {
            printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�\n[1]ͼ�鿨����\n[2]��Ա����\n[3]��Ա�Ա�\n[4]������һ���˵�\n");
            fflush(stdin);
            option = getchar();
            fflush(stdin);
            switch (option) {
                case '1': {
                    printf("Enter new password:");//���������и�ȷ�ϵĹ��̰�
                    scanf("%s", user->password);
                    fflush(stdin);
                    break;
                }
                case '2': {
                    printf("Enter new name:");
                    scanf("%s", user->name);
                    fflush(stdin);
                    break;
                }
                case '3': {
                    printf("Enter new sex([0]Male[1]Female):");
                    scanf("%d", &user->sex);
                    fflush(stdin);
                    break;
                }
                case '4': {
                    system("cls");
                    return;
                }
                default:
                    printf("Input Error!Please Enter again:");
                    break;
            }
        }
        //��ʾ�û���Ϣ
        system("cls");
        display_person_pointer(user);
        for (int i = 0; i < borrow_quantity; ++i) {
            if(i==0)printf("\t\t\t--------Book borrowed--------\n");
            printf("Book_id:%d\n", user->book_id[i]);
            //display(book_id)չʾ�鼮��Ϣ
            display_book_code(book_data, user->book_id[i]);
        }
        //�����ж�
        if (exit_flag == 1)printf("Input error, please enter again:");
        exit_flag = 0;
        //ѯ���Ƿ����
        printf("whether to continue or not�� [1]Yes  [0]No\n");
        option = getchar();
        fflush(stdin);
        if (option == '0') {
            system("cls");
            return;
        }
        else if (option == '1') {
            continue;
        }
        else {
            exit_flag = 1;
            continue;
        }
    }
}


void borrow_book(book_list *book_data,person *current_user){
    system("cls");
    printf("Borrow book\nPress any key to continue:\n");
    getchar();
    fflush(stdin);
    system("cls");
}

void return_book(book_list *book_data,person *current_user){
    system("cls");
    printf("Return book\nPress any key to continue:\n");
    getchar();
    fflush(stdin);
    system("cls");
}
