//
// Created by ��һ�� on 2019/3/12 0012.
//
#include "lib.h"

//�軹�鹦�ܺ���

void  reader_center(book_list *book_data,person *current_user){
    //printf("reader_center\n");
    //printf("Press any key to continue:\n");
    char        choice;
    printf("\t\t\t[1]Manage personal info---[2]Borrow book\n"
           "\t\t\t[3]Return book-----------------[4]Return\n");
    while(1){
        fflush(stdin);
        choice=getchar();
        fflush(stdin);
        switch(choice){
            case   '1':
                //��ʾ������Ϣ+�޸�
                self_manage(book_data,current_user);
                break;
            case   '2':
                //����
                borrow_book(book_data,current_user);
                break;
            case   '3':
                //����
                return_book(book_data,current_user);
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

void self_manage(book_list *book_data,person *current_user) {
    int borrow_quantity = current_user->borrow_quantity;
    int exit_flag = 0;
    char option;
    system("cls");
    display_person(current_user);
    for (int i = 0; i < borrow_quantity; ++i) {
        printf("Book_id:%d\n", current_user->book_id[i]);
        //display(book_id)չʾ�鼮��Ϣ
        display_book(book_data,current_user->book_id[i]);
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
                    //scanf("%s", current_user->password);
                    fflush(stdin);
                    break;
                }
                case '2': {
                    printf("Enter new name:");
                    scanf("%s", current_user->name);
                    fflush(stdin);
                    break;
                }
                case '3': {
                    printf("Enter new sex([0]Male[1]Female):");
                    scanf("%d", &current_user->sex);
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
        display_person(current_user);
        //�����ж�
        if (exit_flag == 1)printf("Input error, please enter again:");
        exit_flag = 0;
        //ѯ���Ƿ����
        printf("whether to continue or not�� [1]Yes  [0]No\n");
        option = getchar();
        fflush(stdin);
        if (option == '0') {
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

void display_person(person *current_user){
    printf("\nUser's infomation:\n"
           "ID:%-5d|Name:%-10s|",current_user->id_number,current_user->name);
    printf("password:%-12s|",current_user->password);
    if(current_user->sex==male)printf("Sex:Male  |\n");
    else if(current_user->sex==female)printf("Sex:Female|\n");
    else printf("Sex:Error\n");
    if(current_user->prop==prop_reader)printf("Property:Reader         |");
    else if(current_user->prop==prop_administrator)printf("Property:Administrator  |");
    else printf("Property:Error  |");
    printf("Penalty:%6.2f       |",current_user->penalty);
    printf("Book borrowed:%-3d\n\n",current_user->borrow_quantity);
}

void display_book(book_list *book_data,int book_id){
    book        *p_book=book_data->head;
    while(p_book->code!=book_id&&p_book!=NULL){
        p_book=p_book->next;
    }
    if(p_book==NULL)printf("Book not found");
    else {
        printf("|Title:%-30s|Author:%-20s|Press:%-20s\n",p_book->book_name,p_book->author_name,p_book->press);
        printf("|Field:");
        switch(p_book->field){
            case 0:
                printf("Science");
                break;
            case 1:
                printf("Literature");
                break;
            case 2:
                printf("Education");
                break;
            case 3:
                printf("Art");
                break;
            case 4:
                printf("Life");
                break;
        }
        printf("         |Price:%4f\n",p_book->price);
        printf("Borrow time:%s",ctime(&p_book->borrow_time));

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
    printf("Borrow book\nPress any key to continue:\n");
    getchar();
    fflush(stdin);
    system("cls");
}
