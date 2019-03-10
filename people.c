#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct Reader)

struct Reader {
    int number;//借书证号码
    char password[13];//借书证密码
    char name[30];//姓名
    char sex;//性别
    int quantity;//借书数量
    int iden[10];//书的编码
    int fine;//罚金
    struct Reader *next;
};

//借书者信息录入
struct Reader *add(void) {
    struct Reader *head;
    struct Reader *p1, *p2;
    int n = 0;
    int i = 0;
    int k = 0;

    p1 = p2 = (struct Reader *) malloc(LEN);
    printf("请输入借书证号码:\n");
    scanf("%d", &p1->number);
    printf("请输入借书证密码:\n");
    scanf("%s", p1->password);
    getchar();
    printf("请输入借书者姓名:\n");
    scanf("%s", p1->name);
    getchar();
    printf("请输入借书者性别:\n");
    scanf("%c", &p1->sex);
    printf("请输入借书数量：\n");
    scanf("%d", &p1->quantity);

    printf("请输入罚金金额：\n");
    scanf("%d", &p1->fine);
    head = NULL;
    while (p1->number != 0) {
        n = n + 1;
        if (n == 1)head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct Reader *) malloc(LEN);
        printf("请输入借书证号码:\n");
        scanf("%d", &p1->number);
        printf("请输入借书证密码:\n");
        scanf("%s", p1->password);
        getchar();
        printf("请输入借书者姓名:\n");
        scanf("%s", p1->name);
        getchar();
        printf("请输入借书者性别:\n");
        scanf("%c", &p1->sex);
        printf("请输入借书数量：\n");
        scanf("%d", &p1->quantity);
        printf("请输入罚金金额：\n");
        scanf("%d", &p1->fine);
    }
    p2->next = NULL;
    return (head);
}

