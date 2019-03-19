
#include "lib.h"

//ʷ���
//��Ա�޸ĺ���

void person_edit(person_list *person_status) {
    int         id_number;
    int         option;
    int         exit_flag=0;
    int         temp;
    while(1) {
        printf("Enter user id:\n");
        scanf("%d",&id_number);
        fflush(stdin);
        person *p_pointer = person_status->head;
        system("cls");
        while (p_pointer->id_number != id_number && p_pointer->next != NULL) {
            p_pointer = p_pointer->next;
        }
        if (p_pointer->id_number == id_number) {
            //��ʾ�û���Ϣ
            display_person(p_pointer);
            printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�\n[1]ͼ�鿨����\n[2]ͼ�鿨����\n[3]��Ա����\n[4]��Ա�Ա�\n[5]��Ա����\n[6]������\n[7]������һ���˵�\n");
            fflush(stdin);
            while (1){
                if(exit_flag!=1) {
                    option=getchar();
                    fflush(stdin);
                    switch (option) {
                        case '1': {
                            printf("Enter new id:");
                            scanf("%d", &p_pointer->id_number);
                            fflush(stdin);
                            break;
                        }
                        case '2': {
                            printf("Enter new password:");
                            scanf("%s", p_pointer->password);
                            fflush(stdin);
                            break;
                        }
                        case '3': {
                            printf("Enter new name:");
                            scanf("%s", p_pointer->name);
                            fflush(stdin);
                            break;
                        }
                        case '4': {
                            printf("Enter new sex([0]Male[1]Female):");
                            temp=p_pointer->sex;
                            scanf("%d", &p_pointer->sex);
                            //���߶��ұ�Ů��
                            if(p_pointer->prop==prop_reader&&temp!=female&&p_pointer->sex==female)
                                person_status->male_reader_size--;
                            //���߶��ұ�����
                            if(p_pointer->prop==prop_reader&&temp!=male&&p_pointer->sex==male)
                                person_status->male_reader_size++;
                            fflush(stdin);
                            break;
                        }
                        case '5': {
                            printf("Enter new prop([0]Reader[1]Admin):");
                            temp=p_pointer->prop;
                            scanf("%d", &p_pointer->prop);
                            //ĳ�˱����Ա
                            if(p_pointer->prop==prop_administrator&&temp!=p_pointer->prop) {
                                //����֮ǰ���еĶ���
                                if (temp==prop_reader&&p_pointer->sex == male)person_status->male_reader_size--;
                                //����Ա����++
                                person_status->admin_size++;
                            }
                            //ĳ�˱����
                            else if(p_pointer->prop==prop_reader&&temp!=p_pointer->prop){
                                //����֮ǰ���е�
                                if(p_pointer->sex == male)person_status->male_reader_size++;
                                //����֮ǰ�ǹ���Ա,����Ա����--
                                if(temp==prop_administrator)person_status->admin_size--;
                            }
                            fflush(stdin);
                            break;
                        }
                        case '6': {
                            printf("Enter new penalty:");
                            scanf("%f", &p_pointer->penalty);
                            fflush(stdin);
                            break;
                        }
                        case '7': {
                            system("cls");
                            return;
                        }
                        default:
                            printf("Input Error!Please Enter again:\n");
                            break;
                    }
                }
                //��ʾ�û���Ϣ
                system("cls");
                display_person(p_pointer);
                //�����ж�
                if(exit_flag==1)printf("Input error, please enter again:\n");
                exit_flag=0;
                //ѯ���Ƿ����
                printf("whether to continue or not�� [0]No  [1]Yes [2]Manage another User\n");
                option=getchar();
                system("cls");
                fflush(stdin);
                if (option== '0') {
                    return;
                }
                else if (option== '1') {
                    display_person(p_pointer);
                    printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�\n[1]ͼ�鿨����\n[2]ͼ�鿨����\n[3]��Ա����\n[4]��Ա�Ա�\n[5]��Ա����\n[6]������\n[7]������һ���˵�\n");
                    continue;
                }
                else if (option=='2'){
                    system("cls");
                    break;
                }
                else {
                    system("cls");
                    exit_flag=1;
                    continue;
                }
            }
        }
        else {
            system("cls");
            printf("User not Found!\n");
            break;
        }
    }
}