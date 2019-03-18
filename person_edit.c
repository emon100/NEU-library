
#include "lib.h"

//史雨迪
//人员修改函数

void person_edit(person_list *person_status) {
    int         id_number;
    char        option;
    int         exit_flag=0;
    while(1) {
        printf("Enter user id:\n");
        scanf("%d",&id_number);
        fflush(stdin);
        person *p_pointer = person_status->head;
        while (p_pointer->id_number != id_number && p_pointer->next != NULL) {
            p_pointer = p_pointer->next;
        }
        if (p_pointer->id_number == id_number) {
            //显示用户信息
            display_person(p_pointer);
            printf("请选择要修改的信息类型：\n[1]图书卡号码\n[2]图书卡密码\n[3]人员姓名\n[4]人员性别\n[5]人员属性\n[6]罚金金额\n[7]返回上一级菜单\n");
            fflush(stdin);
            while (1){
                if(exit_flag!=1) {
                    option=getchar();
                    fflush(stdin);
                    switch (option) {
                        case '1': {
                            printf("Enter new id:");
                            scanf("%d", &p_pointer->id_number);
                            fflush(stdin);
                            break;
                        }
                        case '2': {
                            printf("Enter new password:");//这个起码得有个确认的过程吧
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
                            printf("Enter new prop([0]Reader[1]Admin):");
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
                        default:
                            printf("Input Error!Please Enter again:");
                            break;
                    }
                }
                //显示用户信息
                system("cls");
                display_person(p_pointer);
                //输入判断
                if(exit_flag==1)printf("Input error, please enter again:");
                exit_flag=0;
                //询问是否继续
                printf("whether to continue or not？ [0]No  [1]Yes [2]Manage another User\n");
                option=getchar();
                fflush(stdin);
                if (option== '0') {
                    system("cls");
                    return;
                }
                else if (option== '1') {
                    printf("请选择要修改的信息类型：\n[1]图书卡号码\n[2]图书卡密码\n[3]人员姓名\n[4]人员性别\n[5]人员属性\n[6]罚金金额\n[7]返回上一级菜单\n");
                    continue;
                }
                else if (option=='2'){
                    break;
                }
                else {
                    exit_flag=1;
                    continue;
                }
            }
        }
        else {
            printf("User not Found!");
            break;
        }
    }
}