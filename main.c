#include "lib.h"
//������������������ʹ�õ�ʱ���һ���Ƕ�ȡ��Ա�ļ���¼

int main(void) {
    int user_id;//��ǰ�û�id
    enum LOGIN_STATUS validity = no_user;//��Ч��-1Ϊ�Ҳ����ˣ�0Ϊ�������1Ϊ�κζ��ߣ�2Ϊ����Ա
    char choice;//�û����������
    /*�˺��鱾��������ָ���ʼ��*/
    person_list *person_data = (person_list *) malloc(sizeof(person_list));
    book_list *book_data = (book_list *) malloc(sizeof(book_list));

    printf("Thank you for using Library system, enter your id number to continue:\n");
    scanf("%d", &user_id);//����һ�³Իس�������
    getchar();
    validity = login(user_id,person_data);
    switch (validity) {
        case no_user        :
            printf("Please login again:no user\n");
            break;
        case password_err   :
            printf("Please login again:password error\n");
            break;
        case as_reader      :
            system("cls");
            printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                   "\t*[1]Statistic----------------------------------------[2]Reader center*\n"
                   "\t\t\t*[3]Quit-------------------------------------------------------------*\n");
            while ((choice = getchar()) != '3') {
                switch (choice) {
                    case '1'    :
                        information(book_data,person_data);
                        break;
                    case '2'    :
                        readercenter(book_data,person_data);
                        break;
                    case '3'    :
                        printf("Thank you for using, goodbye!");
                        break;
                    default     :printf("error");
                }
            }
            break;
        case as_admin     :
            system("cls");
            printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                   "\t\t\t*[1]Statistic----------------------------------------[2]Reader center*\n"
                   "\t\t\t*[3]Manage system---------------------------------------------[4]Quit*\n");
            while ((choice = getchar()) != '4') {
                switch (choice) {
                    case '1'    :
                        information(book_data,person_data);
                        break;
                    case '2'    :
                        readercenter(book_data,person_data);
                        break;
                    case '3'    :
                        setting(book_data,person_data);
                        break;
                    case '4'    :
                        printf("Thank you for using, goodbye!");
                        break;
                    default     :printf("error");
                }
                break;
            }
    }
}
