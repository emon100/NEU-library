#include "library.h"

//������������������ʹ�õ�ʱ���һ�����Ƕ�ȡ��Ա�ļ���¼

person *admin_init(void){
    person *admin=(person *)malloc(sizeof(person));
    admin->id_number=1;
    strcpy(admin->name,"admin");
    strcpy(admin->password,"pass");
    admin->prop=administrator;
    person *reader=admin->next=(person*)malloc(sizeof(person));
    reader->id_number=100;
    strcpy(reader->name,"emon");
    strcpy(reader->password,"123");
    reader->prop=readerlv1;
    reader->next=NULL;
    return admin;
}

int login(int user_id){
    //���Ե�¼
    person              *p1         =admin_init();
    int                 validity    =0;
    char *password_tmp=(char *)malloc(sizeof(char)*13);
    while(1){
        if(user_id==p1->id_number){
            switch(p1->prop){
                case administrator:     validity=2;break;
                case readerlv1    :     ;
                case readerlv2    :     ;
                case readerlv3    :     validity=1;break;
            }
            printf("%s,����������:\n",p1->name);//��ʱ��϶���Ӧ�ó�����
            scanf("%s",password_tmp);
            if(strcmp(p1->password,password_tmp)==0){
                free(password_tmp);
                return validity;
            else    return 0;
        }
        else continue;
        if(p1->next==NULL)
            break;
        else        p1=p1->next;
    }
    free(password_tmp);
    return             -1;
}

int main(void) {
    int                 user_id;//��ǰ�û�id
    int                 validity=1;//��Ч��0Ϊ�������-1Ϊ�Ҳ����ˣ�1Ϊ�κζ��ߣ�2Ϊ����Ա
    printf("��ӭʹ��ͼ�����ϵͳ�����ȵ�¼!\n");
    scanf("%d", &user_id);
    validity=login(user_id);
    if(validity>0){
        printf("*��ӭʹ��ͼ�����ϵͳ������������ѡ������Ҫ�Ĺ���*\n"
           "*���ܣ�[1]��ѯͳ��    [2]����ϵͳ                *\n");
        if(validity==1)printf("reader");
        if(validity==2)printf("admin");
    }
    else if(validity==0)printf("�������");
    else printf("�޴��û�\n");
}
