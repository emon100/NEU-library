
#include "lib.h"

//��Ա�޸ĺ���

void person_edit(person_list *person_status,int id_number) {
    char option;
    char flag;
    person *p_pointer=person_status->head;
    while (p_pointer->id_number != id_number && p_pointer->next != NULL) {
        p_pointer = p_pointer->next;
    }
    if (p_pointer->id_number == id_number) {
        printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�[1]ͼ�鿨����\n[2]ͼ�鿨����\n[3]��Ա����\n[4]��Ա�Ա�\n[5]��Ա����\n[6]������\n");
        scanf("%c", &option);
        fflush(stdin);
        switch (option) {
            case '1': {
                scanf("%d", &p_pointer->id_number);
                fflush(stdin);
                break;
            }
            case '2': {
                scanf("%s", p_pointer->password);
                fflush(stdin);
                break;
            }
            case '3': {
                scanf("%s", p_pointer->name);
                fflush(stdin);
                break;
            }
            case '4': {
                scanf("%d", &p_pointer->sex);
                fflush(stdin);
                break;
            }
            case '5': {
                scanf("%d", &p_pointer->prop);
                fflush(stdin);
                break;
            }
            case '6': {
                scanf("%f", &p_pointer->penalty);
                fflush(stdin);
                break;
            }
        }
        printf("whether to continue or not? [0]Yes [1]No\n");
        while (flag = getchar()) {
            if (flag == '1') break;

            else if (flag == '0') {
                printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�[1]ͼ�鿨����\n[2]ͼ�鿨����\n[3]��Ա����\n[4]��Ա�Ա�\n[5]��Ա����\n[6]������\n");
                scanf("%c", &option);
                fflush(stdin);
                switch (option) {
                    case '1': {
                        scanf("%d", &p_pointer->id_number);
                        fflush(stdin);
                        break;
                    }
                    case '2': {
                        scanf("%s", p_pointer->password);
                        fflush(stdin);
                        break;
                    }
                    case '3': {
                        scanf("%s", p_pointer->name);
                        fflush(stdin);
                        break;
                    }
                    case '4': {
                        scanf("%d", &p_pointer->sex);
                        fflush(stdin);
                        break;
                    }
                    case '5': {
                        scanf("%d", &p_pointer->prop);
                        fflush(stdin);
                        break;
                    }
                    case '6': {
                        scanf("%f", &p_pointer->penalty);
                        fflush(stdin);
                        break;
                    }

                }
                printf("whether to continue or not? [0]Yes [1]No\n");
            } else {
                printf("����������ָ��\n");
                continue;
            }
        }

    }

}