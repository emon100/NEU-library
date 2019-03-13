#include "lib.h"

#define LEN sizeof(person)

void            fsh(void) {
    while ('\n' != getchar());
}

//借书者信息录入
person * add(person_list *per_info) {
    person *head;
    person *p_start, *p_next;
    person_list * status;
    status->size=0;
    status->admin_size=0;
    status->male_reader_size=0;
    int n = 0;
    int i = 0;
    int k = 0;
    int flag;


    per_info->head = p_start = p_next = (person *) malloc(LEN);
    printf("请输入图书卡号码:\n");
    scanf("%d", &p_start->id_number);
    fsh();
    printf("请输入图书卡密码:\n");
    scanf("%s", p_start->password);
    fsh();
    printf("请输入人员姓名:\n");
    scanf("%s", p_start->name);
    fsh();
    printf("请输入人员性别：[0]男性 [1]女性\n");
    scanf("%d", p_start->sex);
    if(p_start->sex ==0) status->male_reader_size ++;
    fsh();
    printf("请输入人员属性:[0]reader [1]admin\n");
    scanf("%d" , &p_start->prop);
    if(p_start->prop==1) status->admin_size ++;
    fsh();
    printf("请输入罚金金额：\n");
    scanf("%d", &p_start->penalty);
    fsh();
    status->size ++;
    printf("whether to continue or not? [0]Yes [1]No\n");
    scanf("%d",&flag);

    if(flag==1){
        p_next->next = NULL;
        per_info->tail=p_next;
        per_info->head=head;
    }

    if(flag==0) {
        do {
            n = n + 1;
            if (n == 1)head = p_start;
            else p_next->next = p_start;
            p_next = p_start;
            p_start = (person *) malloc(LEN);
            printf("请输入图书卡号码:\n");
            scanf("%d", &p_start->id_number);
            fsh();
            printf("请输入图书卡密码:\n");
            scanf("%s", p_start->password);
            fsh();
            printf("请输入人员姓名:\n");
            scanf("%s", p_start->name);
            fsh();
            printf("请输入人员性别：[0]男性 [1]女性\n");
            scanf("%d", p_start->sex);
            if(p_start->sex ==0) status->male_reader_size ++;
            fsh();
            printf("请输入人员属性:[0]reader [1]admin\n");
            scanf("%d" , &p_start->prop);
            if(p_start->prop==1) status->admin_size ++;
            fsh();
            printf("请输入罚金金额：\n");
            scanf("%d", &p_start->penalty);
            fsh();
            status->size ++;
            printf("whether to continue or not? [0]Yes [1]No\n");
            scanf("%d",&flag);
            if(flag==1)  break;
        } while (p_start->id_number != 0);
    }
    p_next->next = NULL;
    per_info->tail=p_next;
    per_info->head=head;
}


