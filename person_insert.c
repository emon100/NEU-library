
#include "lib.h"
//史雨迪
//人员插入函数
//获取的参数为person_list类型的一个变量
void person_insert(person_list *person_data) {
    person      *p_new=person_data->tail;
    int         flag;
    printf("您正在添加新的用户.是否要继续? [1]是 [0]否\n");
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
            printf("请输入人员姓名:\n");
            gets(p_new->name);
            fflush(stdin);
            printf("请输入图书卡密码(最多12位):\n");
            gets(p_new->password);
            fflush(stdin);
            printf("请输入人员属性:[0]reader [1]admin\n");
            scanf("%d", &p_new->prop);
            if (p_new->prop == prop_administrator) person_data->admin_size++;
            fflush(stdin);
            printf("请输入人员性别:[0]男性 [1]女性\n");
            scanf("%d", &p_new->sex);
            if (p_new->sex == male&&p_new->prop==prop_reader) person_data->male_reader_size++;
            fflush(stdin);
            printf("请输入罚金金额：\n");
            scanf("%f", &p_new->penalty);
            fflush(stdin);
            memset(p_new->book_code,0, sizeof(int)*10);
            p_new->next = NULL;
            person_data->size++;
            person_data->id_number++;
            person_data->tail = p_new;
            display_person_pointer(p_new);
            printf("是否要继续? [1]是 [0]否\n");
        }
        else {
            fflush(stdin);
            printf("请重新输入指令\n");
            continue;
        }
    }
}

