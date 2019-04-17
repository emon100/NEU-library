
#include "lib.h"

//史雨迪
//人员修改函数

void person_edit(person_list *person_data) {
    int         id_number;
    int         option;
    int         exit_flag=0;
    int         ok;
    int         temp;
    char        current[200];
    person      *p_pointer;
    while(1) {
        ok=0;
        printf("请输入用户账号:\n");
        scanf("%d",&id_number);
        fflush(stdin);
        system("cls");
        //人员匹配
        p_pointer=search_person_pointer(id_number,person_data);
        if (p_pointer==NULL) {
            system("cls");
            printf("并未找到此用户!\n");
            return;
        }
        else if (p_pointer->id_number == id_number) {
            //显示用户信息
            display_person_pointer(p_pointer);
            printf("请选择要修改的信息类型：\n[1]图书卡号码\n[2]图书卡密码\n[3]人员姓名\n[4]人员性别\n[5]人员属性\n[6]罚金金额\n[7]返回上一级菜单\n");
            fflush(stdin);
            while (1){
                if(exit_flag!=1) {
                    option=getchar();
                    fflush(stdin);
                    switch (option) {
                        case '1': {
                            printf("输入新的账号:");
                            scanf("%d", &p_pointer->id_number);
                            fflush(stdin);
                            break;
                        }
                        case '2': {
                            printf("输入新的密码:");
                            while(!ok){
                                gets(current);
                                if(strlen(current)>12){
                                    printf("\n数据过长,请重新输入：");
                                }
                                else ok=1;
                            }
                            ok=0;
                            strcpy(p_pointer->password,current);
                            fflush(stdin);
                            break;
                        }
                        case '3': {
                            printf("输入新的姓名:");
                            while(!ok){
                                gets(current);
                                if(strlen(current)>30){
                                    printf("\n数据过长,请重新输入：");
                                }
                                else ok=1;
                            }
                            ok=0;
                            strcpy(p_pointer->name,current);
                            fflush(stdin);
                            break;
                        }
                        case '4': {
                            printf("输入新的性别: [0]男性 [1]女性");
                            temp=p_pointer->sex;
                            scanf("%d", &p_pointer->sex);
                            //读者而且变女性
                            if(p_pointer->prop==prop_reader&&temp!=female&&p_pointer->sex==female)
                                person_data->male_reader_size--;
                            //读者而且变男性
                            if(p_pointer->prop==prop_reader&&temp!=male&&p_pointer->sex==male)
                                person_data->male_reader_size++;
                            fflush(stdin);
                            break;
                        }
                        case '5': {
                            printf("输入新的人员属性: [0]读者 [1]管理员");
                            temp=p_pointer->prop;
                            scanf("%d", &p_pointer->prop);
                            //读者和error变管理员
                            if(p_pointer->prop==prop_administrator&&temp!=p_pointer->prop) {
                                //而且之前是男的读者
                                if (temp==prop_reader&&p_pointer->sex == male)person_data->male_reader_size--;
                                //管理员数量++
                                person_data->admin_size++;
                            }
                            //管理员和error变读者
                            else if(p_pointer->prop==prop_reader&&temp!=p_pointer->prop){
                                //而且之前是男的
                                if(p_pointer->sex == male)person_data->male_reader_size++;
                                //而且之前是管理员,管理员数量--
                                if(temp==prop_administrator)person_data->admin_size--;
                            }
                            //管理员和读者变error
                            else if((p_pointer->prop!=prop_administrator||p_pointer->prop!=prop_reader)&&(temp==prop_reader||temp==prop_administrator)){
                               if(temp==prop_administrator)person_data->admin_size--;
                               if(temp==prop_reader&&p_pointer->sex==male)person_data->male_reader_size--;
                            }
                            fflush(stdin);
                            break;
                        }
                        case '6': {
                            printf("输入新的罚金金额:");
                            scanf("%f", &p_pointer->penalty);
                            fflush(stdin);
                            break;
                        }
                        case '7': {
                            fflush(stdin);
                            system("cls");
                            return;
                        }
                        default:
                            fflush(stdin);
                            printf("输入错误! 请再次输入:\n");
                            break;
                    }
                }
                //显示用户信息
                system("cls");
                display_person_pointer(p_pointer);
                //输入判断
                if(exit_flag==1)printf("输入错误! 请再次输入:\n");
                exit_flag=0;
                //询问是否继续
                printf("是否继续？ [0]否  [1]是 [2]管理另一个用户\n");
                option=getchar();
                system("cls");
                fflush(stdin);
                if (option== '0') {
                    return;
                }
                else if (option== '1') {
                    display_person_pointer(p_pointer);
                    printf("请选择要修改的信息类型:\n[1]图书卡号码\n[2]图书卡密码\n[3]人员姓名\n[4]人员性别\n[5]人员属性\n[6]罚金金额\n[7]返回上一级菜单\n");
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
            printf("比未找到此用户!\n");
            return;
        }
    }
}