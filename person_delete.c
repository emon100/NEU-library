
#include "lib.h"
//ʷ���
//��Աɾ������
void person_delete(person_list *person_data) {
    //����user_id
    int id_number;
    char option;
    person *person_previous;//ǰһ���ڵ�
    person *person_delete;//ɾ���Ľڵ�

    printf("��������Ҫɾ�����û��˺�:\n");
    scanf("%d", &id_number);
    fflush(stdin);

    person_delete = person_previous = person_data->head;

    if (person_delete == NULL) {
        printf("û������\n");
        return;
    }
    if (id_number==current_user->id_number) {
        printf("����ɾ����ǰ�û�!\n");
        return;
    }

    //���ɾͷ��
    if (person_delete->id_number == id_number) {
        printf("�û���Ϣ:\n");
        display_person_pointer(person_delete);
        printf("�Ƿ���Ҫɾ��? ���� 1 �Լ���,��������������ȡ���˴β���:\n");
        option = getchar();
        fflush(stdin);
        if (option == '1') {
            person_data->head = person_delete->next;
            //�����ж��޸�����
            person_data->size--;
            if (person_delete->prop == prop_administrator)person_data->admin_size--;
            if (person_delete->prop == prop_reader && person_delete->sex == male)person_data->male_reader_size--;
            free(person_delete);
            printf("ɾ�����!\n");
        }
        else {
            printf("ɾ��ʧ��. ���ڷ���...\n");
            return;
        }
    }
    //�����ͷ��
    else {
        person_delete=person_delete->next;
        if(person_delete==NULL){
            printf("û���ҵ���Ҫɾ��������\n");
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
            printf("û���ҵ���Ҫɾ��������\n");
            return;
        }
        else if (person_delete->id_number == id_number) {
            printf("�û���Ϣ:\n");
            display_person_pointer(person_delete);
            printf("�Ƿ���Ҫɾ��? ���� 1 �Լ���,��������������ȡ���˴β���:\n");
            option = getchar();
            fflush(stdin);
            if (option == '1') {
                person_previous->next = person_delete->next;
                //�����β����ô�޸�β��
                if(person_delete==person_data->tail)
                    person_data->tail=person_previous;
                //�����ж��޸�����
                person_data->size--;
                if (person_delete->prop == as_admin)
                    person_data->admin_size--;
                if (person_delete->prop == as_reader && person_delete->sex == male)
                    person_data->male_reader_size--;
                free(person_delete);
                printf("ɾ�����!\n");
            }
            else {
                printf("ɾ��ʧ��. ���ڷ���...\n");
                return;
            }
        }
        else {
            printf("û���ҵ���Ҫɾ��������\n");
            return;
        }
    }
}