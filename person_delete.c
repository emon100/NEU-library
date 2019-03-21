
#include "lib.h"
//史雨迪
//人员删除函数
void person_delete(person_list *person_data) {
    //输入user_id
    int id_number;
    char option;
    person *person_previous;//前一个节点
    person *person_delete;//删除的节点

    printf("Enter the ID of the user that you'd like to delete:\n");
    scanf("%d", &id_number);
    fflush(stdin);

    person_delete = person_previous = person_data->head;

    if (person_delete == NULL) {
        printf("没有数据\n");
        return;
    }
    if (id_number==current_user->id_number) {
        printf("不能删除当前用户!\n");
        return;
    }

    //如果删头部
    if (person_delete->id_number == id_number) {
        printf("User info:\n");
        display_person_pointer(person_delete);
        printf("Still delete? Press 1 to continue,another key to abort:\n");
        option = getchar();
        fflush(stdin);
        if (option == '1') {
            person_data->head = person_delete->next;
            //进行判断修改总览
            person_data->size--;
            if (person_delete->prop == prop_administrator)person_data->admin_size--;
            if (person_delete->prop == prop_reader && person_delete->sex == male)person_data->male_reader_size--;
            free(person_delete);
            printf("Delete finished\n");
        }
        else {
            printf("Delete aborted. Returning\n");
            return;
        }
    }
    //如果非头部
    else {
        person_delete=person_delete->next;
        if(person_delete==NULL){
            printf("没有找到您要删除的数据\n");
            return;
        }
        else{
        while (person_delete->id_number != id_number) {
            person_delete = person_delete->next;
            person_previous = person_previous->next;
            if(person_delete==NULL)break;
            }
        }
        if(person_delete==NULL){
            printf("没有找到您要删除的数据\n");
            return;
        }
        else if (person_delete->id_number == id_number) {
            printf("User info:\n");
            display_person_pointer(person_delete);
            printf("Still delete? Press 1 to continue, press another key to abort:\n");
            option = getchar();
            fflush(stdin);
            if (option == '1') {
                person_previous->next = person_delete->next;
                //如果是尾部那么修改尾部
                if(person_delete==person_data->tail)
                    person_data->tail=person_previous;
                //进行判断修改总览
                person_data->size--;
                if (person_delete->prop == as_admin)
                    person_data->admin_size--;
                if (person_delete->prop == as_reader && person_delete->sex == male)
                    person_data->male_reader_size--;
                free(person_delete);
                printf("Delete finished!\n");
            }
            else {
                printf("Delete aborted. Returning...\n");
                return;
            }
        }
        else {
            printf("没有找到您要删除的数据\n");
            return;
        }
    }
}