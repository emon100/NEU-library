#include "lib.h"
//测试用链表函数，真正使用的时候第一步是读取人员文件登录

int main(void) {
    int                 user_id;//当前用户id
    enum LOGIN_STATUS   validity=no_user;//有效性-1为找不到人，0为密码错误，1为任何读者，2为管理员
    printf("欢迎使用图书管理系统，请先输入自己的读者号登录!\n");
    scanf("%d", &user_id);//考虑一下吃回车的问题
    validity=login(user_id);
    switch(validity){
        case no_user        :
            printf("Please login again:no user\n");break;
        case password_err   :
            printf("Please login again:password error\n");break;
        case as_reader      :
            system("cls");
            printf("\t\t\t*欢迎使用图书管理系统,请输入数字选择你需要的功能*\n"
                   "\t\t\t*[1]查询统计----------------------[2]读者系统*\n"
                   "\t\t\t*[3]退出系统--------------------------------*\n");break;
        case as_admin     :
            system("cls");
            printf("\t\t\t*欢迎使用图书管理系统,请输入数字选择你需要的功能*\n"
                   "\t\t\t*[1]查询统计----------------------[2]读者系统*\n"
                   "\t\t\t*[3]管理员系统--------------------[4]退出系统*\n");break;
    }
    getchar();
    getchar();
}
