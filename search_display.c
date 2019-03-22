//
// Created by emon100 on 2019/3/21 0021.
//
#include "lib.h"

void search_book(book_list *book_data) {
    system("cls");
    book *book_pointers[10] = {0};
    book *current_book = book_data->head;
    int flag[5] = {0};
    int count;
    int choice;
    char book_keywords[400];
    char search_blurred[200] = {0};

    int code;
    char name[100];
    char author[200];
    enum field field;
    //TODO：循环初始化变量
    while (1) {
        memset(flag, 0, sizeof(int) * 5);
        memset(search_blurred, 0, sizeof(char) * 200);
        count = 0;
        system("cls");
        printf("欢迎使用查找系统!\n请选择功能：\n"
               "[1]模糊查找功能\n[2]筛选功能\n[0]退出\n");
        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                printf("输入关键词:\n");
                gets(search_blurred);
                while (current_book != NULL) {
                    sprintf(book_keywords, "%d %s %s %s %d", current_book->code, current_book->book_name,
                            current_book->author_name, current_book->press, current_book->person_id_number);
                    if (strstr(search_blurred, book_keywords) != NULL && count < 10) {
                        book_pointers[count] = current_book;
                        count++;
                    } else break;
                }
                for (int i = 0; i < count; ++i) {
                    display_book_pointer(book_pointers[i]);
                }
                getchar();
                fflush(stdin);
                break;
            case 2:
                printf("输入0以不用书籍条码查找，输入其他内容继续\n");
                if (getchar() == '0')flag[0] = 1;
                fflush(stdin);
                printf("输入0以不用书名查找，输入其他内容继续\n");
                if (getchar() == '0')flag[1] = 1;
                fflush(stdin);
                printf("输入0以不用作者名查找，输入其他内容继续\n");
                if (getchar() == '0')flag[2] = 1;
                fflush(stdin);
                printf("输入0以不用专业领域查找，输入其他内容继续\n");
                if (getchar() == '0')flag[3] = 1;
                fflush(stdin);
                printf("输入0搜索结果不筛选借走的书，输入其他内容搜索结果只有未借走的书\n");
                if (getchar() == '0')flag[4] = 1;
                fflush(stdin);
                if (flag[0] == 0) {
                    printf("输入条码：\n");
                    scanf("%d", &code);
                    fflush(stdin);
                    display_book_code(code,book_data);
                    break;
                }
                if (flag[1] == 0) {
                    printf("输入书名：\n");
                    gets(name);
                    fflush(stdin);
                }
                if (flag[2] == 0) {
                    printf("输入作者：\n");
                    gets(name);
                    fflush(stdin);
                }
                if (flag[3] == 0) {
                    printf("输入专业领域\n[0]科学[1]文学[2]教育[3]艺术[4]生活\n");
                    scanf("%d", &field);
                    fflush(stdin);
                }
                if (flag[0] != 1) {
                    display_book_code(code, book_data);
                } else {
                    while (current_book != NULL) {
                        if (count < 10) {
                            if (strstr(name, current_book->book_name) != NULL || flag[1]) {
                                if (strstr(author, current_book->author_name) != NULL || flag[2]) {
                                    if (current_book->field == field || flag[3]) {
                                        if (current_book->person_id_number == -1 || flag[4]) {
                                            book_pointers[count] = current_book;
                                            count++;
                                        }
                                    }
                                }
                            }
                        } else break;
                        current_book = current_book->next;
                    }
                    if(count==0){
                        printf("没有找到指定书籍\n");
                        break;
                    }
                    for (int i = 0; i < count; i++) {
                        display_book_pointer(book_pointers[i]);
                    }
                }
                getchar();
                fflush(stdin);
                break;
            case 0:
                system("cls");
                return;
            default:
                printf("输入错误请重新输入:\n");
                break;
        }
        printf("是否继续查询，输入1继续，其他键取消\n");
        if(getchar()=='1'){
            fflush(stdin);
            system("cls");
            continue;
        }
        else {
            fflush(stdin);
            system("cls");
            break;
        }

    }
}
/*

void search_user(person_list *person_data){
    while (1) {
        memset(flag, 0, sizeof(int) * 5);
        memset(search_blurred, 0, sizeof(char) * 200);
        count = 0;
        system("cls");
        printf("欢迎使用查找系统!\n请选择功能：\n"
               "code=你要搜索的条码\n"
               "book_name=你要搜索的书名\n"
               "author_name=你要搜索的作者名\n"
               "专业领域\n"
               "borrowed=-1来筛选被借走的书\n"
               "[1]模糊查找功能\n[2]筛选功能\n[0]退出");
        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                gets(search_blurred);
                while (current_book != NULL) {
                    sprintf(book_keywords, "%d %s %s %s %d", current_book->code, current_book->book_name,
                            current_book->author_name, current_book->press, current_book->person_id_number);
                    if (strstr(search_blurred, book_keywords) != NULL && count < 10) {
                        book_pointers[count] = current_book;
                        count++;
                    } else break;
                }
                for (int i = 0; i < count; ++i) {
                    display_book_pointer(book_pointers[i]);
                }
                getchar();
                fflush(stdin);
                break;
            case 2:
                printf("输入0以不用书籍条码查找，输入其他内容继续\n");
                if (getchar() == '0')flag[0] = 1;
                fflush(stdin);
                printf("输入0以不用书名查找，输入其他内容继续\n");
                if (getchar() == '0')flag[1] = 1;
                fflush(stdin);
                printf("输入0以不用作者名查找，输入其他内容继续\n");
                if (getchar() == '0')flag[2] = 1;
                fflush(stdin);
                printf("输入0以不用专业领域查找，输入其他内容继续\n");
                if (getchar() == '0')flag[3] = 1;
                fflush(stdin);
                printf("输入0搜索结果不筛选借走的书，输入其他内容搜索结果只有未借走的书\n");
                if (getchar() == '0')flag[4] = 1;
                fflush(stdin);
                if (flag[0] == 0) {
                    printf("输入条码：\n");
                    scanf("%d", &code);
                    fflush(stdin);
                    display_book_code(code,book_data);
                    break;
                }
                if (flag[1] == 0) {
                    printf("输入书名：\n");
                    gets(name);
                    fflush(stdin);
                }
                if (flag[2] == 0) {
                    printf("输入作者：\n");
                    gets(name);
                    fflush(stdin);
                }
                if (flag[3] == 0) {
                    printf("输入专业领域\n[0]科学[1]文学[2]教育[3]艺术[4]生活\n");
                    scanf("%d", &field);
                    fflush(stdin);
                }
                if (flag[0] != 1) {
                    display_book_code(code, book_data);
                } else {
                    while (current_book != NULL) {
                        if (count < 10) {
                            if (strstr(name, current_book->book_name) != NULL || flag[1]) {
                                if (strstr(author, current_book->author_name) != NULL || flag[2]) {
                                    if (current_book->field == field || flag[3]) {
                                        if (current_book->person_id_number == -1 || flag[4]) {
                                            book_pointers[count] = current_book;
                                            count++;
                                        }
                                    }
                                }
                            }
                        } else break;
                        current_book = current_book->next;
                    }
                    for (int i = 0; i < count; i++) {
                        display_book_pointer(book_pointers[i]);
                    }
                }
                getchar();
                fflush(stdin);
                break;
            case 0:
                return;
            default:
                printf("输入错误请重新输入:\n");
                break;
        }
        printf("是否继续查询，输入1继续，其他键取消\n");
        if(getchar()=='1'){
            fflush(stdin);
            continue;
        }
        else {
            fflush(stdin);
            break;
        }
    }
}
*/
void display_person_pointer(person *user){
    printf("用户信息:\n"
           "|ID:%-10d\n|姓名:%-10s\n",user->id_number,user->name);
    printf("|密码:%-12s\n",user->password);
    if(user->sex==male)printf("|性别:男性  \n");
    else if(user->sex==female)printf("|性别:女性\n");
    else printf("性别:未知\n");
    if(user->prop==prop_reader)printf("|属性:读者\n");
    else if(user->prop==prop_administrator)printf("|属性:管理员");
    else printf("|属性:未知");
    printf("|罚金:%.2f\n",user->penalty);
    printf("|已借书籍数量:%-3d\n\n",user->borrow_quantity);
}

void display_book_pointer(book *p_book) {
    time_t now, borrow_time, return_time;
    printf("|标题:%s\n|作者:%-20s\n|出版社:%-20s\n", p_book->book_name, p_book->author_name, p_book->press);
    printf("|领域:");
    switch (p_book->field) {
        case science:
            printf("科学");
            break;
        case literature:
            printf("文学");
            break;
        case education:
            printf("教育");
            break;
        case art:
            printf("艺术");
            break;
        case life:
            printf("生活");
            break;
        default:
            printf("未知");
            break;
    }
    printf("\n|价格:%6.2f\n\n", p_book->price);
    if (p_book->person_id_number == -1)
        return;
    else {
        printf("借书者:%d\n\n", p_book->person_id_number);
        now = time(NULL);
        borrow_time = p_book->borrow_time;
        return_time = p_book->borrow_time + 5184000;//2个月的秒数是2678400故，time_t类型其实和long差不多
        printf("当前时间:%s\n", ctime(&now));
        printf("借书时间:%s\n", ctime(&borrow_time));
        printf("规定还书时间:%s\n", ctime(&return_time));
    }
}

void display_book_code(int code, book_list *book_data){
    book        *p_book=search_book_pointer(code,book_data);
    if(p_book==NULL)
        printf("无法找到此书!\n");
    else
        display_book_pointer(p_book);
}

//搜索指定的书对应的节点
//有可能返回NULL
book *search_book_pointer(int code,book_list *book_data){
    book *book_current=book_data->head;
    if(book_current==NULL)return book_current;
    while(book_current->code!=code){
        book_current=book_current->next;
        if(book_current==NULL)return book_current;
    }
    return book_current;
}

//搜索指定的人对应的节点
//有可能返回NULL
person *search_person_pointer(int id,person_list *person_data) {
    person *person_current = person_data->head;
    if (person_current == NULL)return person_current;
    while (person_current->id_number != id) {
        person_current = person_current->next;
        if (person_current == NULL)return person_current;
    }
    return person_current;
}

