#include "lib.h"
//������������������ʹ�õ�ʱ���һ���Ƕ�ȡ��Ա�ļ���¼

int main(void) {
    int                 user_id;//��ǰ�û�id
    enum LOGIN_STATUS   validity=no_user;//��Ч��-1Ϊ�Ҳ����ˣ�0Ϊ�������1Ϊ�κζ��ߣ�2Ϊ����Ա
    printf("��ӭʹ��ͼ�����ϵͳ�����ȵ�¼!\n");
    scanf("%d", &user_id);
    validity=login(user_id);
    switch(validity){
        case no_user        : printf("Please login again:no user\n");break;
        case password_err   : printf("Please login again:password error\n");break;
        case reader         : printf("*��ӭʹ��ͼ�����ϵͳ������������ѡ������Ҫ�Ĺ���*\n"
                                     "*���ܣ�[1]��ѯͳ��    [2]����ϵͳ               *\n"
                                     "*[3]�˳�                                        *\n");break;
        case admin          : printf("*��ӭʹ��ͼ�����ϵͳ������������ѡ������Ҫ�Ĺ���*\n"
                                     "*���ܣ�[1]��ѯͳ��    [2]����ϵͳ               *\n"
                                     "*[3]����Աϵͳ        [4]�˳�                  *\n");break;
    }
    getchar();
    getchar();
}
