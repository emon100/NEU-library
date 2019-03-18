/*制作人：贾浩楠
 * 函数功能：修改图书信息
 */

#include"lib.h"
void book_change(book_list*book_data){
    int     code            =0;
    book    *head;
    book    *book_current;
    int     choice          =0;
    char    current[200];
    char    a;

    //信息输入
    printf("Please input the book_code:");
    scanf("%d",&code);//获得要修改书的条码

    //书本匹配
    book_current=head=book_data->head;
    while(book_current->code!=code)book_current=book_current->next;//匹配书籍条码，获得所修改书籍的指针

    //信息修改
        //初次修改
        printf("Please choose the information you want to change");
        printf("1.book_name\n2.author_name\n3.press\n4.field\n5.price\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Please input new book_name:");
                scanf("%s", current);
                strcpy(book_current->book_name, current);
                break;
            }//图书名修改

            case 2: {
                printf("Please input new author_name:");
                scanf("%s", current);
                strcpy(book_current->author_name, current);
                break;
            }//作者名修改

            case 3: {
                printf("Please input new press:");
                scanf("%s", current);
                strcpy(book_current->press, current);
                break;
            }//出版社修改

            case 4: {
                book_data->book_size_field[book_current->field]-1;
                printf("Please input new field:");
                scanf("%d", &book_current->field);
                book_data->book_size_field[book_current->field]+1;//领域数变动
                break;
            }

            case 5: {
                printf("Please input new price:");
                scanf("%f", &book_current->price);
                break;
            }

            default:
                printf("Please input the right number!");
        }

        //循环修改
        while(1){
            printf("Do you want to continue?\nPlease input Y to continue or else to exit");
            scanf("%c",&a);
            if(a=='Y'){printf("Please choose the information you want to change");
            printf("1.book_name\n2.author_name\n3.press\n4.field\n5.price\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    printf("Please input new book_name:");
                    scanf("%s", current);
                    strcpy(book_current->book_name, current);
                    break;
                }//图书名修改

                case 2: {
                    printf("Please input new author_name:");
                    scanf("%s", current);
                    strcpy(book_current->author_name, current);
                    break;
                }//作者名修改

                case 3: {
                    printf("Please input new press:");
                    scanf("%s", current);
                    strcpy(book_current->press, current);
                    break;
                }//出版社修改

                case 4: {
                    book_data->book_size_field[book_current->field]-1;
                    printf("Please input new field:");
                    scanf("%d", &book_current->field);
                    book_data->book_size_field[book_current->field]+1;//领域数变动
                    break;
                }

                case 5: {
                    printf("Please input new price:");
                    scanf("%f", &book_current->price);
                    break;
                }

                default:
                    printf("Please input the right number!");
            }}//Y： 继续修改
            else break;//其他： 退出程序
        }
    }


