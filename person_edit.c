
#include "lib.h"

//��Ա�޸ĺ���

void person_edit(person_list *person_status,int id_number) {
    char option;
    person *p_pointer=person_status->head;
    while (p_pointer->id_number != id_number && p_pointer->next != NULL) {
        p_pointer = p_pointer->next;
    }
    if (p_pointer->id_number == id_number) {
        fflush(stdin);
        //��ʾ�û���Ϣ
        printf("User's infomation:\n"
               "ID:%-5d|Name:%-10s|",p_pointer->id_number,p_pointer->name);
        printf("password:%-12s|",p_pointer->password);
        if(p_pointer->sex==male)printf("Sex:Male  |\n");
        else printf("Sex:Female|\n");
        if(p_pointer->prop==prop_reader)printf("Property:Reader      |\n");
        else printf("Property:Administrator|");
        printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�\n[1]ͼ�鿨����\n[2]ͼ�鿨����\n[3]��Ա����\n[4]��Ա�Ա�\n[5]��Ա����\n[6]������\n[7]������һ���˵�");
        scanf("%c", &option);
        fflush(stdin);
        while(option=getchar()) {
            fflush(stdin);
            switch (option) {
                case '1': {
                    printf("Enter new id:");
                    scanf("%d", &p_pointer->id_number);
                    fflush(stdin);
                    break;
                }
                case '2': {
                    printf("Enter new password:");//���������и�ȷ�ϵĹ��̰�
                    //scanf("%s", p_pointer->password);
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
                    scanf("%d", &p_pointer->sex);
                    fflush(stdin);
                    break;
                }
                case '5': {
                    printf("Enter new prop([0]Admin[1]Reader):");
                    scanf("%d", &p_pointer->prop);
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
                    return;
                }
            }
            //��ʾ�û���Ϣ
            printf("User's infomation:\n"
                   "ID:%-5d|Name:%-10s|",p_pointer->id_number,p_pointer->name);
            printf("password:%-12s|",p_pointer->password);
            if(p_pointer->sex==male)printf("Sex:Male  |\n");
            else printf("Sex:Female|\n");
            if(p_pointer->prop==prop_reader)printf("Property:Reader       |\n");
            else printf("Property:Administrator|");
            //ѯ���Ƿ����
            printf("whether to continue or not? [1]Yes [0]No\n");
            if(getchar()=='0'){
                fflush(stdin);
                return;
            }
            else    {
                printf("��ѡ��Ҫ�޸ĵ���Ϣ���ͣ�\n[1]ͼ�鿨����\n[2]ͼ�鿨����\n[3]��Ա����\n[4]��Ա�Ա�\n[5]��Ա����\n[6]������\n[7]������һ���˵�");
                continue;
            }
        }
    }
}