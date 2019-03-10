#include "lib.h"
//测试用链表函数，真正使用的时候第一步是读取人员文件登录

int main(void) {
    int                 user_id;//当前用户id
    enum LOGIN_STATUS   validity=no_user;//有效性-1为找不到人，0为密码错误，1为任何读者，2为管理员

    /*人和书本数据类型指针初始化*/
    person_list         *person_data  = (person_list *)malloc(sizeof(person_list));
    book_list           *book_data    = (book_list *)malloc(sizeof(book_list));

    printf("Thank you for using Library system, enter your id number to continue:\n");
    scanf("%d", &user_id);//考虑一下吃回车的问题
    validity=login(user_id);
    switch(validity){
        case no_user        :
            printf("Please login again:no user\n");break;
        case password_err   :
            printf("Please login again:password error\n");break;
        case as_reader      :
            system("cls");
            printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                   "\t\t\t*[1]Statistic----------------------------------------[2]Reader center*\n"
                   "\t\t\t*[3]Quit-------------------------------------------------------------*\n");break;
        case as_admin     :
            system("cls");
            printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                   "\t\t\t*[1]Statistic----------------------------------------[2]Reader center*\n"
                   "\t\t\t*[3]Manage system---------------------------------------------[4]Quit*\n");break;
    }
    getchar();
    getchar();
}
