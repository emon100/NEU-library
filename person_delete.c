
#include "lib.h"
//史雨迪
//人员删除函数
//TODO:把person_data里面的size之类的各项信息都要动态调整
void person_delete(person_list *person_data) {
    //输入user_id
    int id_number;
    char option;
    scanf("%d", &id_number);
    fflush(stdin);
    person *person_previous;//前一个节点
    person *person_delete;//删除的节点

    person_delete = person_previous = person_data->head;

    if (person_delete == NULL) {
        printf("没有数据");
        return;
    }

    //如果删头部
    if (person_delete->id_number == id_number) {
        printf("User info:\n");
        display_person(person_delete);
        printf("Still delete? Press 1 to continue:\n");
        option = getchar();
        fflush(stdin);
        if (option == '1') {
            person_data->head = person_delete->next;
            //进行判断修改总览
            person_data->size--;
            if (person_delete->prop == as_admin)person_data->admin_size--;
            if (person_delete->prop == as_reader && person_delete->sex == male)person_data->male_reader_size--;

            free(person_delete);
            printf("Delete finished");
        }
        else {
            printf("Delete aborted. Returning\n");
            return;
        }
    }
    //如果非头部
    else {
        person_delete=person_delete->next;
        while (person_delete->id_number != id_number && person_delete!= NULL) {
            person_delete=person_delete->next;
            person_previous = person_previous->next;
        }
        if (person_delete->id_number == id_number) {
            printf("User info:\n");
            display_person(person_delete);
            printf("Still delete? Press 1 to continue:\n");
            option = getchar();
            fflush(stdin);
            if (option == '1') {
                person_previous->next = person_delete->next;
                //进行判断修改总览
                person_data->size--;
                if (person_delete->prop == as_admin)person_data->admin_size--;
                if (person_delete->prop == as_reader && person_delete->sex == male)person_data->male_reader_size--;
                free(person_delete);
                printf("Delete finished");
            }
            else {
                printf("Delete aborted. Returning\n");
                return;
            }
        }
        else {
            printf("没有找到您要删除的数据\n");
            return;
        }
    }
}