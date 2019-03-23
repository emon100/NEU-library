#include "lib.h"
/*
 * author:emon100
 */
person *current_user=NULL;

int main(void) {
    int                 exit_flag=0;
    int                 user_id;//��ǰ�û�id
    enum login_status   validity;//��Ч��-1Ϊ�Ҳ����ˣ�0Ϊ�������1Ϊ�κζ��ߣ�2Ϊ����Ա
    char choice;//�û����������
    /*�˺��鱾��������ָ���ʼ��*/
    person_list *person_data = (person_list *) malloc(sizeof(person_list));
    book_list *book_data = (book_list *) malloc(sizeof(book_list));
    person_recovery(person_data);
    book_recovery(book_data);
    //�˵����ֿ�ʼ
    while(1){
        system("cls");
        printf("\t\t\t��ӭʹ��ͼ�����ϵͳ!\n�����������˺��Լ���:\n");
        scanf("%d", &user_id);
        fflush(stdin);
        validity = login(user_id,person_data);
        switch (validity) {
            case no_user        :
                printf("�����µ�¼!\t������ʾ:û�и��û�\n\n�����κ������Լ���:\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case password_err   :
                printf("�����µ�¼!\t������ʾ:�������!\n\n�����κ������Լ���:\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case as_reader      :
                system("cls");
                printf("\t\t\t\t�𾴵Ķ���,��л��ʹ��ͼ�����ϵͳ,������ָ����ѡ����\n"
                       "\t\t\t\t[1]������Ϣ���ѯ\n"
                       "\t\t\t\t[2]��������\n"
                       "\t\t\t\t[3]�����û�\n"
                       "\t\t\t\t[4]����\n"
                       "\t\t\t\t[5]�˳�\n");
                fflush(stdin);//�Իس�
                while ((choice = getchar())) {
                    fflush(stdin);//�Իس�
                    switch (choice) {
                        case '1'    :
                            system("cls");
                            information_reader(book_data);
                            break;
                        case '2'    :
                            system("cls");
                            reader_center(book_data, current_user);
                            break;
                        case '3'    :
                            system("cls");
                            exit_flag=1;
                            break;
                        case '4'    :
                            system("cls");
                            help();
                            break;
                        case '5'    :
                            system("cls");
                            printf("Thank you for using, goodbye!\n");
                            return 0;
                        default     :
                            system("cls");
                            printf("�����������������!\n");
                            break;
                    }
                    if(exit_flag==1){
                        exit_flag=0;
                        break;
                    }
                    fflush(stdin);//�Իس�
                    printf("\t\t\t\t�𾴵Ķ���,��л��ʹ��ͼ�����ϵͳ,������ָ����ѡ����\n"
                           "\t\t\t\t[1]������Ϣ���ѯ\n"
                       "\t\t\t\t[2]��������\n"
                       "\t\t\t\t[3]�����û�\n"
                       "\t\t\t\t[4]����\n"
                       "\t\t\t\t[5]�˳�\n");
                }
                break;
            case as_admin     :
                system("cls");
                printf("\t\t\t\t�𾴵Ĺ���Ա,��л��ʹ��ͼ�����ϵͳ,������ָ����ѡ����\n"
                       "\t\t\t\t[1]������Ϣ���ѯ\n"
                       "\t\t\t\t[2]��������\n"
                       "\t\t\t\t[3]����ϵͳ\n"
                       "\t\t\t\t[4]�����û�\n"
                       "\t\t\t\t[5]����\n"
                       "\t\t\t\t[6]�˳�\n");
                fflush(stdin);
                while ((choice = getchar())) {
                    fflush(stdin);//�Իس�
                    switch (choice) {
                        case '1'    :
                            system("cls");
                            information_admin(book_data, person_data);
                            break;
                        case '2'    :
                            system("cls");
                            reader_center(book_data, current_user);
                            break;
                        case '3'    :
                            system("cls");
                            manage(book_data, person_data);
                            break;
                        case '4'    :
                            system("cls");
                            exit_flag=1;
                            break;
                        case '5'    :
                            system("cls");
                            help();
                            break;
                        case '6'    :
                            system("cls");
                            printf("��л����ʹ��,�´��ټ�!\n");return 0;
                        default     :
                            system("cls");
                            printf("���ٴ�����ָ��!\n");
                            break;
                    }
                    if(exit_flag==1){
                        exit_flag=0;
                        break;
                    }
                    printf("\t\t\t\t�𾴵Ĺ���Ա,��л��ʹ��ͼ�����ϵͳ,������ָ����ѡ����\n"
                           "\t\t\t\t[1]������Ϣ���ѯ\n"
                           "\t\t\t\t[2]��������\n"
                           "\t\t\t\t[3]����ϵͳ\n"
                           "\t\t\t\t[4]�����û�\n"
                           "\t\t\t\t[5]����\n"
                           "\t\t\t\t[6]�˳�\n");
                    fflush(stdin);//�Իس�
                }
            break;
        }
    }
}
