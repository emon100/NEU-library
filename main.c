#include "lib.h"
/*
 * author:emon100
 */

person *current_user=NULL;

int main(void) {
    int                 exit_flag=0;
    int                 user_id;//当前用户id
    enum login_status   validity = no_user;//有效性-1为找不到人，0为密码错误，1为任何读者，2为管理员
    char choice;//用户输入的命令
    /*人和书本数据类型指针初始化*/
    person_list *person_data = (person_list *) malloc(sizeof(person_list));
    book_list *book_data = (book_list *) malloc(sizeof(book_list));
    admin_init(person_data);
    book_test(book_data);
    system("cls");
    printf("Thank you for using Library system, enter your id number to continue:\n");
    scanf("%d", &user_id);
    fflush(stdin);
    validity = login(user_id,person_data);
    switch (validity) {
        case no_user        :
            printf("Please login again:no user\n");
            break;
        case password_err   :
            printf("Please login again:password error\n");
            break;
        case as_reader      :
            system("cls");
            fflush(stdin);//吃回车
            printf("id:%5d--name:%10s--borrow:%5d\n",current_user->id_number,current_user->name,current_user->borrow_quantity);//测试current_user
            printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                   "\t\t\t*[1]Statistic----------------------------------------[2]Reader center*\n"
                   "\t\t\t*[3]Quit-------------------------------------------------------------*\n");
            while (choice = getchar()) {
                fflush(stdin);//吃回车
                switch (choice) {
                    case '1'    :
                        system("cls");
                        information_reader(book_data);
                        break;
                    case '2'    :
                        system("cls");
                        reader_center(book_data,current_user);
                        break;
                    case '3'    :
                        system("cls");
                        printf("Thank you for using, goodbye!\n");
                        return 0;
                    default     :
                        system("cls");
                        printf("Please enter again\n");
                        break;
                }
                printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                       "\t\t\t*[1]Statistic----------------------------------------[2]Reader center*\n"
                       "\t\t\t*[3]Quit-------------------------------------------------------------*\n");
            }
            break;
        case as_admin     :
            system("cls");
            printf("id:%5d--name:%10s--borrow:%5d\n",current_user->id_number,current_user->name,current_user->borrow_quantity);//测试current_user
            printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                   "\t\t\t*[1]library's info-----------------------------------[2]Reader center*\n"
                   "\t\t\t*[3]Manage system---------------------------------------------[4]Quit*\n");
            fflush(stdin);
            while (choice = getchar()) {
                fflush(stdin);//吃回车
                switch (choice) {
                    case '1'    :
                        system("cls");
                        information_admin(book_data,person_data);
                        break;
                    case '2'    :
                        system("cls");
                        reader_center(book_data,current_user);
                        break;
                    case '3'    :
                        system("cls");
                        manage(book_data,person_data);
                        break;
                    case '4'    :
                        system("cls");
                        printf("Thank you for using, goodbye!\n");
                        return 0;
                    default     :
                        system("cls");
                        printf("Please enter again!\n");
                        break;
                }
                printf("\t\t\t*Thank you for using Library system, enter number to choose functions*\n"
                       "\t\t\t*[1]library's info-----------------------------------[2]Reader center*\n"
                       "\t\t\t*[3]Manage system---------------------------------------------[4]Quit*\n");
            }
            break;
    }
}
