#include "lib.h"

#define LEN sizeof(person)

void            fsh(void) {
    while ('\n' != getchar());
}

//��������Ϣ¼��
person * add(person_list *status) {
    person *p_start, *p_next;
    status->size                =0;
    status->admin_size          =0;
    status->male_reader_size    =0;
    char flag;


    status->head = p_start = p_next = (person *) malloc(sizeof(person));
    printf("������ͼ�鿨����:\n");
    scanf("%d", &p_start->id_number);
    fsh();
    printf("������ͼ�鿨����:\n");
    scanf("%s", p_start->password);
    fsh();
    printf("��������Ա����:\n");
    scanf("%s", p_start->name);
    fsh();
    printf("��������Ա�Ա�[0]���� [1]Ů��\n");
    scanf("%d", p_start->sex);
    if(p_start->sex ==0) status->male_reader_size ++;
    fsh();
    printf("��������Ա����:[0]reader [1]admin\n");
    scanf("%d" , &p_start->prop);
    if(p_start->prop==1) status->admin_size ++;
    fsh();
    printf("�����뷣���\n");
    scanf("%d", &p_start->penalty);
    fsh();
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
            fsh();
            printf("������ͼ�鿨����:\n");
            scanf("%s", p_start->password);
            fsh();
            printf("��������Ա����:\n");
            scanf("%s", p_start->name);
            fsh();
            printf("��������Ա�Ա�[0]���� [1]Ů��\n");
            scanf("%d", p_start->sex);
            if (p_start->sex == 0) status->male_reader_size++;
            fsh();
            printf("��������Ա����:[0]reader [1]admin\n");
            scanf("%d", &p_start->prop);
            if (p_start->prop == 1) status->admin_size++;
            fsh();
            printf("�����뷣���\n");
            scanf("%d", &p_start->penalty);
            fsh();
            status->size++;
        } else {
            printf("����������ָ��\n");
            continue;
        }
    }
    p_next->next = NULL;
    status->tail=p_next;
}