#include "lib.h"
person * add(person_list *status) {
    person *p_start, *p_next;
    status->size                =0;
    status->admin_size          =0;
    status->male_reader_size    =0;

    int flag;


    status->head = p_start = p_next = (person *) malloc(sizeof(person));
    printf("������ͼ�鿨����:\n");
    scanf("%d", &p_start->id_number);
    fflush(stdin);
    printf("������ͼ�鿨����:\n");
    scanf("%s", p_start->password);
    fflush(stdin);
    printf("��������Ա����:\n");
    scanf("%s", p_start->name);
    fflush(stdin);
    printf("��������Ա�Ա�[0]���� [1]Ů��\n");
    scanf("%d", &p_start->sex);
    if(p_start->sex ==0) status->male_reader_size ++;
    fflush(stdin);
    printf("��������Ա����:[0]reader [1]admin\n");
    scanf("%d" , &p_start->prop);
    if(p_start->prop==1) status->admin_size ++;
    fflush(stdin);
    printf("�����뷣���\n");
    scanf("%f", &p_start->penalty);
    fflush(stdin);
    status->size ++;
    printf("whether to continue or not? [0]Yes [1]No\n");
    while(flag=getchar()) {
        if (flag == '1') {
            p_next->next = NULL;
            status->tail = p_next;
            break;
        } else if (flag == '0') {
            p_next->next = p_start;
            p_next = p_start;
            p_start = (person *) malloc(sizeof(person));
            printf("������ͼ�鿨����:\n");
            scanf("%d", &p_start->id_number);
            fflush(stdin);
            printf("������ͼ�鿨����:\n");
            scanf("%s", p_start->password);
            fflush(stdin);
            printf("��������Ա����:\n");
            scanf("%s", p_start->name);
            fflush(stdin);
            printf("��������Ա�Ա�[0]���� [1]Ů��\n");
            scanf("%d", &p_start->sex);
            if (p_start->sex == 0) status->male_reader_size++;
            fflush(stdin);
            printf("��������Ա����:[0]reader [1]admin\n");
            scanf("%d", &p_start->prop);
            if (p_start->prop == 1) status->admin_size++;
            fflush(stdin);
            printf("�����뷣���\n");
            scanf("%f", &p_start->penalty);
            fflush(stdin);
            status->size++;
        }
        else {
            printf("����������ָ��\n");
            continue;
        }
    }
    p_next->next = NULL;
    status->tail=p_next;
}
