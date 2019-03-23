#include "lib.h"
/*
 * author:emon100
 */
person *current_user=NULL;

int main(void) {
    int                 exit_flag=0;
    int                 user_id;//当前用户id
    enum login_status   validity;//有效性-1为找不到人，0为密码错误，1为任何读者，2为管理员
    char choice;//用户输入的命令
    /*人和书本数据类型指针初始化*/
    person_list *person_data = (person_list *) malloc(sizeof(person_list));
    book_list *book_data = (book_list *) malloc(sizeof(book_list));
    person_recovery(person_data);
    book_recovery(book_data);
    //菜单部分开始
    while(1){
        system("cls");
        printf("\t\t\t欢迎使用图书管理系统!\n请输入您的账号以继续:\n");
        scanf("%d", &user_id);
        fflush(stdin);
        validity = login(user_id,person_data);
        switch (validity) {
            case no_user        :
                printf("请重新登录!\t错误提示:没有该用户\n\n输入任何内容以继续:\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case password_err   :
                printf("请重新登录!\t错误提示:密码错误!\n\n输入任何内容以继续:\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case as_reader      :
                system("cls");
                printf("\t\t\t\t尊敬的读者,感谢您使用图书管理系统,请输入指令来选择功能\n"
                       "\t\t\t\t[1]总览信息与查询\n"
                       "\t\t\t\t[2]读者中心\n"
                       "\t\t\t\t[3]更换用户\n"
                       "\t\t\t\t[4]帮助\n"
                       "\t\t\t\t[5]退出\n");
                fflush(stdin);//吃回车
                while ((choice = getchar())) {
                    fflush(stdin);//吃回车
                    switch (choice) {
                        case '1'    :
                            system("cls");
                            information_reader(book_data);
                            break;
                        case '2'    :
                            system("cls");
                            reader_center(book_data, current_user);
                            break;
                        case '3'    :
                            system("cls");
                            exit_flag=1;
                            break;
                        case '4'    :
                            system("cls");
                            help();
                            break;
                        case '5'    :
                            system("cls");
                            printf("Thank you for using, goodbye!\n");
                            return 0;
                        default     :
                            system("cls");
                            printf("输入错误请重新输入!\n");
                            break;
                    }
                    if(exit_flag==1){
                        exit_flag=0;
                        break;
                    }
                    fflush(stdin);//吃回车
                    printf("\t\t\t\t尊敬的读者,感谢您使用图书管理系统,请输入指令来选择功能\n"
                           "\t\t\t\t[1]总览信息与查询\n"
                       "\t\t\t\t[2]读者中心\n"
                       "\t\t\t\t[3]更换用户\n"
                       "\t\t\t\t[4]帮助\n"
                       "\t\t\t\t[5]退出\n");
                }
                break;
            case as_admin     :
                system("cls");
                printf("\t\t\t\t尊敬的管理员,感谢您使用图书管理系统,请输入指令来选择功能\n"
                       "\t\t\t\t[1]总览信息与查询\n"
                       "\t\t\t\t[2]读者中心\n"
                       "\t\t\t\t[3]管理系统\n"
                       "\t\t\t\t[4]更换用户\n"
                       "\t\t\t\t[5]帮助\n"
                       "\t\t\t\t[6]退出\n");
                fflush(stdin);
                while ((choice = getchar())) {
                    fflush(stdin);//吃回车
                    switch (choice) {
                        case '1'    :
                            system("cls");
                            information_admin(book_data, person_data);
                            break;
                        case '2'    :
                            system("cls");
                            reader_center(book_data, current_user);
                            break;
                        case '3'    :
                            system("cls");
                            manage(book_data, person_data);
                            break;
                        case '4'    :
                            system("cls");
                            exit_flag=1;
                            break;
                        case '5'    :
                            system("cls");
                            help();
                            break;
                        case '6'    :
                            system("cls");
                            printf("感谢您的使用,下次再见!\n");return 0;
                        default     :
                            system("cls");
                            printf("请再次输入指令!\n");
                            break;
                    }
                    if(exit_flag==1){
                        exit_flag=0;
                        break;
                    }
                    printf("\t\t\t\t尊敬的管理员,感谢您使用图书管理系统,请输入指令来选择功能\n"
                           "\t\t\t\t[1]总览信息与查询\n"
                           "\t\t\t\t[2]读者中心\n"
                           "\t\t\t\t[3]管理系统\n"
                           "\t\t\t\t[4]更换用户\n"
                           "\t\t\t\t[5]帮助\n"
                           "\t\t\t\t[6]退出\n");
                    fflush(stdin);//吃回车
                }
            break;
        }
    }
}
