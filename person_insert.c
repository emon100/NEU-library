
#include "lib.h"
//ʷ���
//��Ա���뺯��
//��ȡ�Ĳ���Ϊperson_list���͵�һ������
void person_insert(person_list *person_data) {
    person      *p_new=person_data->tail;
    int         flag;
    printf("����������µ��û�.�Ƿ�Ҫ����? [1]�� [0]��\n");
    fflush(stdin);
    while (1) {
        flag = getchar();
        fflush(stdin);
        if  (flag == '0') {
            system("cls");
            break;
        }
        else if (flag == '1') {
            system("cls");
            p_new->next = (person *) malloc(sizeof(person));
            p_new=p_new->next;
            p_new->id_number=person_data->id_number;
            p_new->borrow_quantity=0;
            fflush(stdin);
            printf("��������Ա����:\n");
            gets(p_new->name);
            fflush(stdin);
            printf("������ͼ�鿨����(���12λ):\n");
            gets(p_new->password);
            fflush(stdin);
            printf("��������Ա����:[0]reader [1]admin\n");
            scanf("%d", &p_new->prop);
            if (p_new->prop == prop_administrator) person_data->admin_size++;
            fflush(stdin);
            printf("��������Ա�Ա�:[0]���� [1]Ů��\n");
            scanf("%d", &p_new->sex);
            if (p_new->sex == male&&p_new->prop==prop_reader) person_data->male_reader_size++;
            fflush(stdin);
            printf("�����뷣���\n");
            scanf("%f", &p_new->penalty);
            fflush(stdin);
            memset(p_new->book_code,0, sizeof(int)*10);
            p_new->next = NULL;
            person_data->size++;
            person_data->id_number++;
            person_data->tail = p_new;
            display_person_pointer(p_new);
            printf("�Ƿ�Ҫ����? [1]�� [0]��\n");
        }
        else {
            fflush(stdin);
            printf("����������ָ��\n");
            continue;
        }
    }
}

