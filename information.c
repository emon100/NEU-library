//
// Created by emon100 on 2019/3/12 0012.
//
#include "lib.h"
//���߲鿴ͳ�Ƶĺ���
void information_reader(book_list *book_data,person_list *person_data){
    char        choice;
    system("cls");
    printf("information_reader\n");//�ǵ�ɾ��
    printf("\t\t\t*Welcome!--------------------------------*\n"
           "\t\t\t*[1]Check statistics-------[2]Search Book*\n"
           "\t\t\t*[3]Return-------------------------------*\n");
    //�˵�
    fsh();
    while(choice=getchar()){
        fsh();
        switch(choice){
            case  '1':
                printf("Total book--science--literature--education--------art--------life\n");
                printf("%5d",book_data->size);
                for(int i=science;i<=life;i++)printf("%12d",book_data->book_size_field[i]);
                printf("\n");
                printf("Press any key to continue:\n");
                getchar();
                fsh();//�Իس�
                system("cls");
                break;
            case  '2':
                printf("search book\n");
                break;
            case  '3':
                system("cls");
                return;
            default:
                system("cls");
                printf("Please enter again!:\n");
                break;
        }
        printf("\t\t\t*Welcome!--------------------------------*\n"
               "\t\t\t*[1]Check statistics-------[2]Search Book*\n"
               "\t\t\t*[3]Return-------------------------------*\n");
    }
}
//����Ա�鿴ͳ�Ƶĺ���
void information_admin(book_list *book_data,person_list *person_data) {
    char choice;
    system("cls");
    printf("information_admin\n");//�ǵ�ɾ��
    printf("\t\t\t*Welcome!--------------------------------*\n"
           "\t\t\t*[1]Check statistics-------[2]Search Book*\n"
           "\t\t\t*[3]Return-------------------------------*\n");
    fsh();
    //���涼�ǲ˵�
    while (choice = getchar()) {
        fsh();
        switch (choice) {
            case '1':
                printf("Total book--science--literature--education--------art--------life\n");
                printf("%5d", book_data->size);
                for (int i = science; i <= life; i++)printf("%12d", book_data->book_size_field[i]);
                printf("\n");
                printf("Total User---Admins---Total readers---male readers---Female readers\n");
                printf("%5d%11d%13d%13d%13d\n",person_data->size,person_data->admin_size,person_data->size-person_data->admin_size,person_data->male_reader_size,person_data->size-person_data->admin_size-person_data->male_reader_size);
                printf("Press any key to continue:\n");
                getchar();
                fsh();
                system("cls");
                break;
            case '2':
                printf("search book\n");
                break;
            case '3':
                system("cls");
                return;
            default:
                system("cls");
                printf("Please enter again!:\n");
                break;
        }
        printf("\t\t\t*Welcome!--------------------------------*\n"
               "\t\t\t*[1]Check statistics-------[2]Search Book*\n"
               "\t\t\t*[3]Return-------------------------------*\n");
    }
}
