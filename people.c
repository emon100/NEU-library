#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct Reader)

struct Reader {
    int number;//����֤����
    char password[13];//����֤����
    char name[30];//����
    char sex;//�Ա�
    int quantity;//��������
    int iden[10];//��ı���
    int fine;//����
    struct Reader *next;
};

//��������Ϣ¼��
struct Reader *add(void) {
    struct Reader *head;
    struct Reader *p1, *p2;
    int n = 0;
    int i = 0;
    int k = 0;

    p1 = p2 = (struct Reader *) malloc(LEN);
    printf("���������֤����:\n");
    scanf("%d", &p1->number);
    printf("���������֤����:\n");
    scanf("%s", p1->password);
    getchar();
    printf("���������������:\n");
    scanf("%s", p1->name);
    getchar();
    printf("������������Ա�:\n");
    scanf("%c", &p1->sex);
    printf("���������������\n");
    scanf("%d", &p1->quantity);

    printf("�����뷣���\n");
    scanf("%d", &p1->fine);
    head = NULL;
    while (p1->number != 0) {
        n = n + 1;
        if (n == 1)head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct Reader *) malloc(LEN);
        printf("���������֤����:\n");
        scanf("%d", &p1->number);
        printf("���������֤����:\n");
        scanf("%s", p1->password);
        getchar();
        printf("���������������:\n");
        scanf("%s", p1->name);
        getchar();
        printf("������������Ա�:\n");
        scanf("%c", &p1->sex);
        printf("���������������\n");
        scanf("%d", &p1->quantity);
        printf("�����뷣���\n");
        scanf("%d", &p1->fine);
    }
    p2->next = NULL;
    return (head);
}

