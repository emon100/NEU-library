/*制作人：贾浩楠
 * 函数功能：修改图书信息
 */

#include"lib.h"
void book_edit(book_list *book_data) {
    int         code = 0;
    int         exit_flag=0,ok;
    book        *book_current;
    int         choice = 0;
    char        current[200];
    while (1) {
        ok=0;
        //信息输入
        printf("请输入书本编码:\n");
        scanf("%d", &code);//获得要修改书的条码
        fflush(stdin);
        system("cls");
        //书本匹配
        book_current=search_book_pointer(code,book_data);
        if (book_current==NULL) {
            system("cls");
            printf("并未找到这本书!\n");
            return;
        }
        //信息修改
        //初次修改
        else if (book_current->code == code) {
            display_book_pointer(book_current);
            printf("请输入指令以更改您想修改的书籍信息:\n");
            printf("[1]书籍名称\n[2]作者姓名\n[3]出版社\n[4]书籍领域\n[5]书籍价格\n[6]返回上级菜单\n");
            fflush(stdin);
            while (1){
                if(exit_flag!=1){
                    choice=getchar();
                    fflush(stdin);
                    switch (choice) {
                        case '1': {
                            printf("请输入新的书籍名称:\n");
                            while(!ok){
                                gets(current);
                                if(strlen(current)>99){
                                    printf("\n数据过长,请重新输入：");
                                }
                                else ok=1;
                            }
                            ok=0;
                            fflush(stdin);
                            strcpy(book_current->book_name, current);
                            break;
                        }//图书名修改

                        case '2': {
                            printf("请输入新的作者姓名:\n");
                            while(!ok){
                                gets(current);
                                if(strlen(current)>199){
                                    printf("\n数据过长,请重新输入：");
                                }
                                else ok=1;
                            }
                            ok=0;
                            fflush(stdin);
                            strcpy(book_current->author_name, current);
                            break;
                        }//作者名修改

                        case '3': {
                            printf("请输入新的出版社:\n");
                            while(!ok){
                                gets(current);
                                if(strlen(current)>49){
                                    printf("\n数据过长,请重新输入：");
                                }
                                else ok=1;
                            }
                            ok=0;
                            fflush(stdin);
                            strcpy(book_current->press, current);
                            break;
                        }//出版社修改

                        case '4': {
                            book_data->book_size_field[book_current->field]--;
                            printf("请输入新的书籍领域:\n");
                            printf("0.科学\n1.文学\n2.教育\n3.艺术\n4.生活\n");
                            scanf("%d", &book_current->field);
                            fflush(stdin);
                            if(book_current->field<=life)
                                book_data->book_size_field[book_current->field]++;//领域数变动
                            break;
                        }

                        case '5': {
                            printf("请输入新的书籍价格:\n");
                            scanf("%f", &book_current->price);
                            fflush(stdin);
                            break;
                        }

                        case '6': {
                            system("cls");
                            fflush(stdin);
                            return;
                        }

                        default:
                            fflush(stdin);
                            printf("输入错误!请重新输入:\n");
                            break;
                    }
                }
                system("cls");
                display_book_pointer(book_current);
                if(exit_flag==1)printf("输入错误!请重新输入:\n");
                exit_flag=0;
                //询问是否继续
                printf("是否要继续？ [0]否  [1]是 [2]管理另一本书籍\n");
                choice=getchar();
                system("cls");
                fflush(stdin);
                if (choice== '0') {
                    return;
                }
                else if (choice== '1') {
                    display_book_pointer(book_current);
                    printf("请输入指令以更改您想修改的书籍信息:\n");
                    printf("[1]书籍名称\n[2]作者姓名\n[3]出版社\n[4]书籍领域\n[5]书籍价格\n[6]返回上级菜单\n");
                    continue;
                }
                else if (choice=='2'){
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
            printf("并未找到这本书籍!\n");
            return;
        }
    }
}

