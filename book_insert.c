/*制作人：贾浩楠
 *函数功能：添加书籍信息
 */

#include"lib.h"

void book_insert(book_list *book_data) {
    char current[201];
    int flag;
    book *book_new;
    book_new = book_data->tail;

    //book信息修改
    printf("You are adding new book.whether to continue or not? [1]Yes [0]No\n");
    fflush(stdin);
    while (1) {
        flag=getchar();
        fflush(stdin);
        if (flag=='0'){
            system("cls");
            break;
        }
        else if (flag=='1') {
            book_new->next = (book *) malloc(sizeof(book));//开辟book缓存区
            book_new=book_new->next;
            book_new->code = book_data->code;

            printf("Please input the book's name:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->book_name, current);//图书名

            printf("Please input the authors' name:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->author_name, current);//作者名

            printf("Please input its press:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->press, current);//出版社

            printf("Please choose its field:\n0.science\n1.literature\n2.education\n3.atr\n4.life\n");
            scanf("%d", &book_new->field);//领域

            printf("Please input its price:\n");
            scanf("%f", &book_new->price);//价格

            book_new->id_number = -1;//借书者号码默认-1表示没人借

            //book_list信息修改
            book_new->next=NULL;
            book_data->size++;//书本总量+1
            book_data->code = book_data->code + 1;//书籍条码添加
            if(book_new->field<=life)
                book_data->book_size_field[book_new->field]++;//相关领域书数量+1
            book_data->tail = book_new;//链表元素+1
            display_book_pointer(book_new);
            printf("whether to continue or not? [1]Yes [0]No\n");
            fflush(stdin);
        }
        else {
            fflush(stdin);
            printf("请重新输入指令\n");
            continue;
        }
    }
}
