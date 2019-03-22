//
// Created by emon100 on 2019/3/12 0012.
//
#include "lib.h"
//读者查看统计的函数
//TODO:搜书搜人
void information_reader(book_list *book_data){
    int choice;
    int book_code;
    system("cls");
    printf("information_reader\n");//记得删掉
    printf("\t\t\t\t欢迎查询!\n"
           "\t\t\t\t[1]总览信息\n"
           "\t\t\t\t[2]查询书籍\n"
           "\t\t\t\t[3]返回上级菜单\n");
    //菜单
    fflush(stdin);
    while(choice=getchar()){
        fflush(stdin);
        switch(choice){
            case  '1':
                printf("\n");
                printf("|--书本总数--|--科学--|-----文学-----|--教育--|-----艺术-----|---生活---|\n  ");
                printf("%5d",book_data->size);
                for(int i=science;i<=life;++i)printf("%12d",book_data->book_size_field[i]);
                printf("\n\n");
                printf("输入任何内容以继续:\n");
                getchar();
                fflush(stdin);//吃回车
                system("cls");
                break;
            case  '2':
                system("cls");
                printf("请输入书籍编码以查询该书本:\n");
                scanf("%d",&book_code);
                fflush(stdin);
                display_book_code(book_code, book_data);
                search_book(book_data);
                break;
            case  '3':
                system("cls");
                return;
            default:
                system("cls");
                printf("请重新输入指令:\n");
                break;
        }
        printf("\t\t\t\t欢迎查询!\n"
               "\t\t\t\t[1]总览信息\n"
               "\t\t\t\t[2]查询书籍\n"
               "\t\t\t\t[3]返回上级菜单\n");
    }
}
//管理员查看统计的函数
void information_admin(book_list *book_data,person_list *person_data) {
    char choice;
    system("cls");
    printf("information_admin\n");//记得删掉
    printf("\t\t\t\t欢迎查询!\n"
           "\t\t\t\t[1]总览信息\n"
           "\t\t\t\t[2]查询书籍\n"
           "\t\t\t\t[3]查询用户\n"
           "\t\t\t\t[4]返回上级菜单\n");
    fflush(stdin);
    //下面都是菜单
    while (choice = getchar()) {
        fflush(stdin);
        switch (choice) {
            case '1':
                system("cls");
                printf("|-书籍总数-|---未还书籍数量---|-科学-|-----文学-----|--教育--|-----艺术-----|---生活---|\n  ");
                printf("%5d%15d", book_data->size,book_data->book_borrowed);
                for (int i = science; i <= life; ++i)printf("%12d", book_data->book_size_field[i]);
                printf("\n\n");
                printf("|-用户总数-|-管理员-|-读者总数-|-男性读者-|-女性读者-|\n");
                printf("%6d%10d%10d%12d%11d\n",person_data->size,person_data->admin_size,person_data->size-person_data->admin_size,person_data->male_reader_size,person_data->size-person_data->admin_size-person_data->male_reader_size);
                printf("输入任何内容以继续:\n");
                getchar();
                fflush(stdin);
                system("cls");
                break;
            case '2':
                system("cls");
                printf("书籍查询\n");
                break;
            case '3':
                system("cls");
                printf("用户查询\n");
                break;
            case '4':
                system("cls");
                return;
            default:
                system("cls");
                printf("请再次输入!:\n");
                break;
        }
        printf("\t\t\t\t欢迎查询!\n"
               "\t\t\t\t[1]总览信息\n"
               "\t\t\t\t[2]查询书籍\n"
               "\t\t\t\t[3]查询用户\n"
               "\t\t\t\t[4]返回上级菜单\n");
    }
}
