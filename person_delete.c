
#include "lib.h"
//ʷ���
//��Աɾ������
//TODO:��person_data�����size֮��ĸ�����Ϣ��Ҫ��̬����
void person_delete(person_list *person_data) {
    //����user_id
    int id_number;
    char option;
    scanf("%d", &id_number);
    fflush(stdin);
    person *person_previous;//ǰһ���ڵ�
    person *person_delete;//ɾ���Ľڵ�

    person_delete = person_previous = person_data->head;

    if (person_delete == NULL) {
        printf("û������");
        return;
    }

    //���ɾͷ��
    if (person_delete->id_number == id_number) {
        printf("User info:\n");
        display_person(person_delete);
        printf("Still delete? Press 1 to continue:\n");
        option = getchar();
        fflush(stdin);
        if (option == '1') {
            person_data->head = person_delete->next;
            //�����ж��޸�����
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
    //�����ͷ��
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
                //�����ж��޸�����
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
            printf("û���ҵ���Ҫɾ��������\n");
            return;
        }
    }
}