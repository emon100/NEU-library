//
// Created by emon100 on 2019/3/8 0008.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "lib.h"


int login(int user_id){
    //���Ե�¼
    person              *p1         =admin_init();
    int                 validity    =password_err;
    char *password_tmp=(char *)malloc(sizeof(char)*13);
    while(1){
        if(user_id==p1->id_number){
            switch(p1->prop){
                case administrator:     validity=admin;break;
                case readerlv1    :     ;
                case readerlv2    :     ;
                case readerlv3    :     validity=reader;break;
            }
            printf("%s,����������:\n",p1->name);//��ʱ��϶���Ӧ�ó�����
            scanf("%s",password_tmp);
            if(strcmp(p1->password,password_tmp)==0){
                free(password_tmp);
                return validity;
            }
            else {
                printf("�����������������:");
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

