//
// Created by ��һ�� on 2019/3/12 0012.
//
#include "lib.h"

//�軹�鹦�ܺ���

void  reader_center(book_list *book_data,person *user){
    //printf("reader_center\n");
    //printf("Press any key to continue:\n");
    int choice;
    penalty(book_data,user);
    printf("\t\t\t[1]�޸�˽����Ϣ\n"
           "\t\t\t[2]����\n"
           "\t\t\t[3]����\n"
           "\t\t\t[4]�����ϼ��˵�\n");
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
                printf("���ٴ�����:\n");
                break;
        }
        printf("\t\t\t[1]�޸�˽����Ϣ\n"
                "\t\t\t[2]����\n"
                "\t\t\t[3]����\n"
                "\t\t\t[4]�����ϼ��˵�\n");
    }
}

void self_manage(book_list *book_data,person *user) {
    int borrow_quantity = user->borrow_quantity;
    int exit_flag = 0;
    int option;
    system("cls");
    penalty(book_data,user);
    display_person_pointer(user);
    for (int i = 0; i < borrow_quantity; ++i) {
        if(i==0)printf("\t\t\t--------�ѽ��鼮--------\n");
        printf("�鱾���:%d\n", user->book_code[i]);
        //display(book_code)չʾ�鼮��Ϣ
        display_book_code(user->book_code[i], book_data);
    }
    while (1) {
        if (exit_flag != 1) {
            printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�\n[1]ͼ�鿨����\n[2]��Ա����\n[3]��Ա�Ա�\n[4]������һ���˵�\n");
            fflush(stdin);
            option = getchar();
            fflush(stdin);
            switch (option) {
                case '1': {
                    printf("�����µ�����:");//���������и�ȷ�ϵĹ��̰�
                    gets(user->password);
                    fflush(stdin);
                    break;
                }
                case '2': {
                    printf("�����µ�����:");
                    gets(user->name);
                    fflush(stdin);
                    break;
                }
                case '3': {
                    printf("�����µ��Ա�([0]����[1]Ů��):");
                    scanf("%d", &user->sex);
                    fflush(stdin);
                    break;
                }
                case '4': {
                    system("cls");
                    return;
                }
                default:
                    printf("�������!���ٴ�����:");
                    break;
            }
        }
        //��ʾ�û���Ϣ
        system("cls");
        penalty(book_data,user);
        display_person_pointer(user);
        for (int i = 0; i < borrow_quantity; ++i) {
            if(i==0)printf("\t\t\t--------�ѽ��鼮--------\n");
            printf("�鼮���:%d\n", user->book_code[i]);
            display_book_code(user->book_code[i], book_data);
        }
        //�����ж�
        if (exit_flag == 1)printf("�������!���ٴ�����:");
        exit_flag = 0;
        //ѯ���Ƿ����
        printf("�Ƿ������ [1]��  [0]��\n");
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

//������㺯��������ʱ��һ��0.2Ԫ
void penalty(book_list *book_data,person *user){
    int         borrow_quantity=user->borrow_quantity;
    float       penalty=0;
    book        *borrowed_book=NULL;
    time_t      now,diff;
    now=time(NULL);
    for (int i=0;i<borrow_quantity;++i){
        borrowed_book=search_book_pointer(user->book_code[i],book_data);
        diff=(now-(borrowed_book->borrow_time+5097600));//��������ʱ����Ӧ��ʱ���ֵ
        if(diff>0)penalty=penalty+(diff/86400)*0.2;
        else continue;
    }
    if(user->penalty<penalty)user->penalty=penalty;
}


void borrow_book(book_list *book_data,person *user){
    int         code;
    char        choice;
    book        *current_book=NULL;

    system("cls");
    fflush(stdin);
    penalty(book_data,user);
    while(1){
        if(user->penalty>0||user->borrow_quantity>=10){
            printf("���޷�����,��Ϊ���Ѿ����˳���10���鼮�������з�����Ҫ֧��!\n");
            return;
        }
        else{
            printf("��������Ҫ����鼮�ı���:\n");
            scanf("%d",&code);
            fflush(stdin);
            current_book = search_book_pointer(code,book_data);
            display_book_pointer(current_book);
            printf("��������Ҫ����鼮��? ���� 1 �Լ���, ��������������ȡ���˴β���:\n");
            choice=getchar();
            fflush(stdin);
            if(choice!='1'){
                system("cls");
                printf("���ν�����ȡ��!\n");
                return;
            }
            if(current_book!=NULL){
               if(current_book->person_id_number==-1){
                   user->borrow_quantity++;
                   user->book_code[user->borrow_quantity]=code;
                   current_book->person_id_number=user->id_number;
                   current_book->borrow_time=time(NULL);
                   book_data->book_borrowed++;
                   printf("����ɹ�!\n");
               }
               else if(current_book->person_id_number!=-1){
                   printf("��Ǹ,�����Ѿ�����.\n");
               }
            }
            else {
                printf("��δ�ҵ��Ȿ�鼮!\n");
            }
            printf("�Ƿ�Ҫ����? ���� 1 ������һ���鼮, ���������������˳�.\n");
            choice=getchar();
            fflush(stdin);
            if(choice=='1')continue;
            else {
                system("cls");
                return;
            }
        }
    }
}

void return_book(book_list *book_data,person *user){
    int         code;
    int         borrow_quantity=user->borrow_quantity;
    int         i;
    char        choice;
    book        *current_book=NULL;
    system("cls");
    fflush(stdin);
    if(user->borrow_quantity>0){
        while(1){
            printf("��������Ҫ�黹���鼮�ı���:\n");
           scanf("%d",&code);
            fflush(stdin);
           current_book=search_book_pointer(code,book_data);
           if(current_book!=NULL&&current_book->person_id_number==user->id_number){
                //����Ԫ�أ������Ԫ�ش������ĳһ���ط��ҵ�
                for(i=0;i<borrow_quantity;++i){
                   if(user->book_code[i]==code){
                       user->book_code[i]=0;
                       break;
                   }
                }
                //�ҵ���Ѻ�һ��Ԫ����ǰ�ƶ�
                for(;i<borrow_quantity-1;++i){
                     if((i+1)<borrow_quantity){
                        user->book_code[i]=user->book_code[i+1];
                     }
                     else break;
                }
                user->borrow_quantity--;
                current_book->person_id_number=-1;
                book_data->book_borrowed--;
                printf("����ɹ�!\n");
           }
           else if(current_book==NULL){
               printf("��δ�ҵ��Ȿ�鼮!\n�������������Լ���:\n");
               getchar();
               fflush(stdin);
           }
           else {
               printf("�����ܹ黹����!\n�������������Լ���:\n");
               getchar();
               fflush(stdin);
           }
            printf("�Ƿ�Ҫ����? ���� 1 �Թ黹��һ���鼮, ���������������˳�.\n");
            choice=getchar();
            fflush(stdin);
            if(choice=='1')continue;
            else {
                system("cls");
                return;
            }
        }
    }
    else{
        printf("����û���鼮Ҫ�黹!\n�������������Է��ز˵�.\n");
        getchar();
        fflush(stdin);
        return;
    }
}
