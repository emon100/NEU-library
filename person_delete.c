
#include "lib.h"
//史雨迪
//人员删除函数
//TODO:把person_data里面的size之类的各项信息都要动态调整
void person_delete(person_list *person_data){
    //输入user_id
    int         id_number;
    scanf("%d",&id_number);
    fflush(stdin);
    person *person_previous,*person_delete,*person_next;
    person_delete=person_previous=person_data->head;
    if(person_previous == NULL){
        printf("没有数据");
        return;
    }
    /*
    if(person_delete->id_number==id_number){
        person_next=person_delete->next;
        free(person_delete);
        person_data->head=person_next;
        person_data
    }
     */
    while(person_previous->id_number != id_number && person_previous->next != NULL){
        person_delete;
        person_previous =person_previous->next;
    }
    if(person_previous->id_number == id_number){
        if(person_previous == person_data->head){
            person_data->head = person_previous->next;
        }
        else{
            person_next->next =person_previous->next;
        }
        free(person_previous);
    }
    else{
        printf("没有找到您要删除的数据\n");
        return;
    }
}