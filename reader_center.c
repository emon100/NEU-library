//
// Created by ��һ�� on 2019/3/12 0012.
//
#include "lib.h"

//�軹�鹦�ܺ���

void  reader_center(book_list *book_data,person *current_user){
    //printf("reader_center\n");
    //printf("Press any key to continue:\n");
    char        choice;
    printf("[1]manage [4]Return");
    while(choice=getchar()){
        fflush(stdin);
        switch(choice){
            case   '1':
                //��ʾ������Ϣ+�޸�
                self_manage(current_user);
                break;
            case   '2':
                //����
                break;
            case   '3':
                //����
                break;
            case   '4':
                //������һ��
                return;
        }
        printf("[1]manage [4]Return");
    }
    getchar();
    fflush(stdin);
    system("cls");
}

void self_manage(person *current_user){
    int             borrow_quantity=current_user->borrow_quantity;
    printf("User's infomation:\n"
           "ID:%-5d|Name:%-10s|",current_user->id_number,current_user->name);
    printf("password:%-12s|",current_user->password);
    if(current_user->sex==male)printf("Sex:Male  |\n");
    else printf("Sex:Female|\n");
    if(current_user->prop==prop_reader)printf("Property:Reader       |\n");
    else printf("Property:Administrator|");
    printf("Book borrowed:%-3d|\n",current_user->borrow_quantity);
    for (int i = 0; i < borrow_quantity; ++i) {
        printf("book_id:%d\n",current_user->book_id[i]);
        //display(book_id)չʾ�鼮��Ϣ
    }
    printf("Penalty:%f\n",current_user->penalty);
    printf("Press any key to continue...");
    getchar();
    fflush(stdin);
}
