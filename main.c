#include "lib.h"
//������������������ʹ�õ�ʱ���һ���Ƕ�ȡ��Ա�ļ���¼

int main(void) {
    int                 user_id;//��ǰ�û�id
    enum LOGIN_STATUS   validity=no_user;//��Ч��-1Ϊ�Ҳ����ˣ�0Ϊ�������1Ϊ�κζ��ߣ�2Ϊ����Ա
    printf("��ӭʹ��ͼ�����ϵͳ�����������Լ��Ķ��ߺŵ�¼!\n");
    scanf("%d", &user_id);//����һ�³Իس�������
    validity=login(user_id);
    switch(validity){
        case no_user        :
            printf("Please login again:no user\n");break;
        case password_err   :
            printf("Please login again:password error\n");break;
        case as_reader      :
            system("cls");
            printf("\t\t\t*��ӭʹ��ͼ�����ϵͳ,����������ѡ������Ҫ�Ĺ���*\n"
                   "\t\t\t*[1]��ѯͳ��----------------------[2]����ϵͳ*\n"
                   "\t\t\t*[3]�˳�ϵͳ--------------------------------*\n");break;
        case as_admin     :
            system("cls");
            printf("\t\t\t*��ӭʹ��ͼ�����ϵͳ,����������ѡ������Ҫ�Ĺ���*\n"
                   "\t\t\t*[1]��ѯͳ��----------------------[2]����ϵͳ*\n"
                   "\t\t\t*[3]����Աϵͳ--------------------[4]�˳�ϵͳ*\n");break;
    }
    getchar();
    getchar();
}
