
#include "lib.h"
//史雨迪
//人员插入函数
//获取的参数为person_list类型的一个变量

void person_insert(person_list *person_data) {
    person *p_previous, *p_new;
    int flag;

    p_previous = p_new = (person *) malloc(sizeof(person));
    person_data->tail->next = p_previous;
    printf("请输入图书卡号码:\n");
    scanf("%d", &p_previous->id_number);
    fflush(stdin);
    printf("请输入图书卡密码:\n");
    scanf("%s", p_previous->password);
    fflush(stdin);
    printf("请输入人员姓名:\n");
    scanf("%s", p_previous->name);
    fflush(stdin);
    printf("请输入人员性别：[0]男性 [1]女性\n");
    scanf("%d", &p_previous->sex);
    if (p_previous->sex == 0) person_data->male_reader_size++;
    fflush(stdin);
    printf("请输入人员属性:[0]reader [1]admin\n");
    scanf("%d", &p_previous->prop);
    if (p_previous->prop == 1) person_data->admin_size++;
    fflush(stdin);
    printf("请输入罚金金额：\n");
    scanf("%f", &p_previous->penalty);
    fflush(stdin);
    person_data->size++;
    printf("whether to continue or not? [0]Yes [1]No\n");
    p_new = p_previous;
    while (flag = getchar()) {
        if      (flag == '1') {
            p_new->next = NULL;
            person_data->tail = p_new;
            break;
        }
        else if (flag == '0') {
            p_new = (person *) malloc(sizeof(person));
            p_previous->next = p_new;
            printf("请输入图书卡号码:\n");
            scanf("%d", &p_new->id_number);
            fflush(stdin);
            printf("请输入图书卡密码:\n");
            scanf("%s", p_new->password);
            fflush(stdin);
            printf("请输入人员姓名:\n");
            scanf("%s", p_new->name);
            fflush(stdin);
            printf("请输入人员性别：[0]男性 [1]女性\n");
            scanf("%d", &p_new->sex);
            if (p_new->sex == 0) person_data->male_reader_size++;
            fflush(stdin);
            printf("请输入人员属性:[0]reader [1]admin\n");
            scanf("%d", &p_new->prop);
            if (p_new->prop == 1) person_data->admin_size++;
            fflush(stdin);
            printf("请输入罚金金额：\n");
            scanf("%f", &p_new->penalty);
            fflush(stdin);
            person_data->size++;
            p_previous = p_new;
            printf("whether to continue or not? [0]Yes [1]No\n");
        }
        else {
            printf("请重新输入指令\n");
            continue;
        }
    }
}

