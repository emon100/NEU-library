
#include "lib.h"

//��Աɾ������

void person_delete(person_list *person_data,int id_number){
    person *person_1,*person_2;
    if(person_1 == NULL){
        printf("û������");
        return;
    }
    while(person_1->id_number != id_number && person_1->next != NULL){
        person_2 =person_1;
        person_1 =person_1->next;
    }
    if(person_1->id_number == id_number){
        if(person_1 == person_data->head){
            person_data->head = person_1->next;
        }
        else{
            person_2->next =person_1->next;
        }
        free(person_1);
    }
    else{
        printf("û���ҵ���Ҫɾ��������");
    }

}