#include"lib.h"

void person_order_in_name(person_list *person_data) {
    person          *former;
    person          *current;
    person          *c_next;
    person          *user;

    if (person_data->size <= 1);
    else{
        for(int i = 1; i <= person_data->size - 1; ++i){
            current = person_data->head;
            c_next  = current->next;

            if(strnicmp(current->name , c_next->name,strlen(current->name))>0){
                current->next = c_next->next;
                c_next->next  = current;
                person_data->head = c_next;
                former = c_next;
                c_next = current->next;
            }

            else{
                former = current;
                current = current->next;
                c_next = c_next->next;
            }

            if(person_data->size==2)break;

            for (int j = 0; j <= person_data->size-3; ++j) {
                if (strnicmp(current->name , c_next->name,strlen(current->name))>0) {   //讨论位置交换的情况
                    current->next = c_next->next;       //前者的尾部变为后者的尾部
                    c_next->next = current;             //后者的尾部变为前者的地址
                    former->next = c_next;              //连接节点
                    former=c_next;                      //将c_next的地址储存在former中
                    c_next = current->next;             //后移
                }
                else {                                  //讨论位置没有发生交换的情况
                    former = current;
                    current = current->next;
                    c_next = c_next->next;              //后移
                }
            }
        }
    }
    user=person_data->head;

    while (user != NULL) {
        printf("\n用户信息:\n"
               "账号:%-5d|姓名:%-10s|",user->id_number,user->name);
        printf("密码:%-12s|",user->password);
        if(user->sex==male)printf("性别:男性  |\n");
        else if(user->sex==female)printf("性别:女性|\n");
        else printf("性别:未知\n");
        if(user->prop==prop_reader)printf("属性:读者         |");
        else if(user->prop==prop_administrator)printf("属性:管理员       |");
        else printf("属性:未知  |");
        printf("罚金:%6.2f       |",user->penalty);
        printf("借书数量:%-3d\n\n",user->borrow_quantity);
        user = user->next;
    }//输出人员信息
    }

