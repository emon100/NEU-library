#include "lib.h"
//������������������ʹ�õ�ʱ���һ���Ƕ�ȡ��Ա�ļ���¼

int main(void) {
    int                 user_id;//��ǰ�û�id
    enum LOGIN_STATUS   validity=no_user;//��Ч��-1Ϊ�Ҳ����ˣ�0Ϊ�������1Ϊ�κζ��ߣ�2Ϊ����Ա

    /*�˺��鱾��������ָ���ʼ��*/
    person_list         *person_data  = (person_list *)malloc(sizeof(person_list));
    book_list           *book_data    = (book_list *)malloc(sizeof(book_list));

    printf("Thank you for using Library system, enter your id number to continue:\n");
    scanf("%d", &user_id);//����һ�³Իس�������
    validity=login(user_id);
    switch(validity){
        case no_user        :
            printf("Please login again:no user\n");break;
        case password_err   :
            printf("Please login again:password error\n");break;
        case as_reader      :
            system("cls");
            printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                   "\t\t\t*[1]Statistic----------------------------------------[2]Reader center*\n"
                   "\t\t\t*[3]Quit-------------------------------------------------------------*\n");break;
        case as_admin     :
            system("cls");
            printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                   "\t\t\t*[1]Statistic----------------------------------------[2]Reader center*\n"
                   "\t\t\t*[3]Manage system---------------------------------------------[4]Quit*\n");break;
    }
    getchar();
    getchar();
}
