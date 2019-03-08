//
// Created by emon100 on 2019/3/8 0008.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "lib.h"


int login(int user_id){
    //测试登录
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
            printf("%s,请输入密码:\n",p1->name);//到时候肯定不应该出名字
            scanf("%s",password_tmp);
            if(strcmp(p1->password,password_tmp)==0){
                free(password_tmp);
                return validity;
            }
            else {
                printf("密码错误请重新输入:");
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

