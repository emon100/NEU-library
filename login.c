//
// Created by emon100 on 2019/3/8 0008.
//
#include "lib.h"


enum login_status login(int user_id,person_list *person_data){
    person              *p1=person_data->head;
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
            printf("%s,ÇëÊäÈëÄãµÄÃÜÂë£º\n",p1->name);
            scanf("%s",password_tmp);
            if(strcmp(p1->password,password_tmp)==0){
                free(password_tmp);
                return validity;
            }
            else {
                printf("ÃÜÂë´íÎó£¬ÇëÔÙ´ÎÊäÈë£º\n");
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
