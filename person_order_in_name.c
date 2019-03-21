#include"lib.h"

void person_order_in_name(person_list *person_data) {
    person          *former;
    person          *current;
    person          *c_next;

    if (person_data->size <= 1);
    else{
        for(int i = 1; i <= person_data->size - 1; ++i){
            current = person_data->head;
            c_next  = current->next;

            if(strcmp(current->name , c_next->name)>0){
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

            for (int j = 3; j <= person_data->size; ++j) {
                if (strcmp(current->name , c_next->name)>0) {   //讨论位置交换的情况
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
}
