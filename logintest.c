//
// Created by emon100 on 2019/3/8 0008.
//
#include "lib.h"


int login(int user_id){
    //测试登录
    person              *p1         =admin_init();
    int                 validity    =password_err;
    int                 characters  =0;
    char                ch;
    char *password_tmp=(char *)malloc(sizeof(char)*13);
    while(1){
        if(user_id==p1->id_number){
            switch(p1->prop){
                case prop_administrator:     validity=as_admin;break;
                case prop_reader    :        validity=as_reader;break;
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
/*
while((ch=getch())!='\n'&&characters<=12) {
printf("*");
*(password_tmp+characters)=ch;
characters++;
}
 */
