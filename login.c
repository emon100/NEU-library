//
// Created by emon100 on 2019/3/8 0008.
//
#include "lib.h"


enum login_status login(int user_id,person_list *persondata){
    //���Ե�¼
    person              *p1=persondata->head;
    enum login_status   validity    =password_err;
    char *password_tmp=(char *)malloc(sizeof(char)*13);
    while(1){
        if(user_id==p1->id_number){
            current_user=p1;
            switch(p1->prop){
                case prop_administrator:
                    validity=as_admin;break;
                case prop_reader       :
                    validity=as_reader;break;
            }
            printf("%s,Enter your password:\n",p1->name);//��ʱ��϶���Ӧ�ó�����
            scanf("%s",password_tmp);
            if(strcmp(p1->password,password_tmp)==0){
                free(password_tmp);
                return validity;
            }
            else {
                printf("Password error,try again:\n");
                scanf("%s",password_tmp);
                if(strcmp(p1->password,password_tmp)==0){
                    free(password_tmp);
                    return validity;
                }
                else
                {
                    free(password_tmp);
                    return password_err;
                }
            }
        }
        if(p1->next==NULL)
        {
            free(password_tmp);
            break;
        }
        else {
            p1 = p1->next;
            continue;
        }
    }
    return             no_user;
}
