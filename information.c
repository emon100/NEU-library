//
// Created by emon100 on 2019/3/12 0012.
//
#include "lib.h"
//���߲鿴ͳ�Ƶĺ���
//TODO:��������
void information_reader(book_list *book_data){
    int choice;
    int book_code;
    system("cls");
    printf("information_reader\n");//�ǵ�ɾ��
    printf("\t\t\t\t��ӭ��ѯ!\n"
           "\t\t\t\t[1]������Ϣ\n"
           "\t\t\t\t[2]��ѯ�鼮\n"
           "\t\t\t\t[3]�����ϼ��˵�\n");
    //�˵�
    fflush(stdin);
    while(choice=getchar()){
        fflush(stdin);
        switch(choice){
            case  '1':
                printf("\n");
                printf("|--�鱾����--|--��ѧ--|-----��ѧ-----|--����--|-----����-----|---����---|\n  ");
                printf("%5d",book_data->size);
                for(int i=science;i<=life;++i)printf("%12d",book_data->book_size_field[i]);
                printf("\n\n");
                printf("�����κ������Լ���:\n");
                getchar();
                fflush(stdin);//�Իس�
                system("cls");
                break;
            case  '2':
                system("cls");
                printf("�������鼮�����Բ�ѯ���鱾:\n");
                scanf("%d",&book_code);
                fflush(stdin);
                display_book_code(book_code, book_data);
                search_book(book_data);
                break;
            case  '3':
                system("cls");
                return;
            default:
                system("cls");
                printf("����������ָ��:\n");
                break;
        }
        printf("\t\t\t\t��ӭ��ѯ!\n"
               "\t\t\t\t[1]������Ϣ\n"
               "\t\t\t\t[2]��ѯ�鼮\n"
               "\t\t\t\t[3]�����ϼ��˵�\n");
    }
}
//����Ա�鿴ͳ�Ƶĺ���
void information_admin(book_list *book_data,person_list *person_data) {
    char choice;
    system("cls");
    printf("information_admin\n");//�ǵ�ɾ��
    printf("\t\t\t\t��ӭ��ѯ!\n"
           "\t\t\t\t[1]������Ϣ\n"
           "\t\t\t\t[2]��ѯ�鼮\n"
           "\t\t\t\t[3]��ѯ�û�\n"
           "\t\t\t\t[4]�����ϼ��˵�\n");
    fflush(stdin);
    //���涼�ǲ˵�
    while (choice = getchar()) {
        fflush(stdin);
        switch (choice) {
            case '1':
                system("cls");
                printf("|-�鼮����-|---δ���鼮����---|-��ѧ-|-----��ѧ-----|--����--|-----����-----|---����---|\n  ");
                printf("%5d%15d", book_data->size,book_data->book_borrowed);
                for (int i = science; i <= life; ++i)printf("%12d", book_data->book_size_field[i]);
                printf("\n\n");
                printf("|-�û�����-|-����Ա-|-��������-|-���Զ���-|-Ů�Զ���-|\n");
                printf("%6d%10d%10d%12d%11d\n",person_data->size,person_data->admin_size,person_data->size-person_data->admin_size,person_data->male_reader_size,person_data->size-person_data->admin_size-person_data->male_reader_size);
                printf("�����κ������Լ���:\n");
                getchar();
                fflush(stdin);
                system("cls");
                break;
            case '2':
                system("cls");
                printf("�鼮��ѯ\n");
                break;
            case '3':
                system("cls");
                printf("�û���ѯ\n");
                break;
            case '4':
                system("cls");
                return;
            default:
                system("cls");
                printf("���ٴ�����!:\n");
                break;
        }
        printf("\t\t\t\t��ӭ��ѯ!\n"
               "\t\t\t\t[1]������Ϣ\n"
               "\t\t\t\t[2]��ѯ�鼮\n"
               "\t\t\t\t[3]��ѯ�û�\n"
               "\t\t\t\t[4]�����ϼ��˵�\n");
    }
}
