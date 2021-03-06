/*制作人：贾浩楠
 *函数功能：添加书籍信息
 */

#include"lib.h"

void book_insert(book_list *book_data) {
    char current[201];
    int flag,ok;
    book *book_new;
    book_new = book_data->tail;

    //book信息修改
    printf("您正在添加一本新的书籍.是否要继续? [1]是 [0]否\n");
    fflush(stdin);
    while (1) {
        flag=getchar();
        ok=0;
        fflush(stdin);
        if (flag=='0'){
            system("cls");
            break;
        }
        else if (flag=='1') {
            system("cls");
            book_new->next = (book *) malloc(sizeof(book));//开辟book缓存区
            book_new=book_new->next;
            book_new->code = book_data->code;

            printf("请输入书籍名称:\n");
            fflush(stdin);
            while(!ok){
                gets(current);
                if(strlen(current)>99){
                    printf("\n数据过长,请重新输入：");
                }
                else ok=1;
            }
            ok=0;
            fflush(stdin);
            strcpy(book_new->book_name, current);//图书名

            printf("请输入作者姓名:\n");
            fflush(stdin);
            while(!ok){
                gets(current);
                if(strlen(current)>199){
                    printf("\n数据过长,请重新输入：");
                }
                else ok=1;
            }
            ok=0;
            fflush(stdin);
            strcpy(book_new->author_name, current);//作者名

            printf("请输入出版社:\n");
            fflush(stdin);
            while(!ok){
                gets(current);
                if(strlen(current)>49){
                    printf("\n数据过长,请重新输入：");
                }
                else ok=1;
            }
            ok=0;
            fflush(stdin);
            strcpy(book_new->press, current);//出版社

            printf("请选择领域:\n0.科学\n1.文学\n2.教育\n3.艺术\n4.生活\n");
            scanf("%d", &book_new->field);//领域
            fflush(stdin);

            printf("请输入价格:\n");
            scanf("%f", &book_new->price);//价格
            fflush(stdin);

            book_new->person_id_number = -1;//借书者号码默认-1表示没人借

            //book_list信息修改
            book_new->next=NULL;
            book_data->size++;//书本总量+1
            book_data->code = book_data->code + 1;//书籍条码添加
            if(book_new->field<=life)
                book_data->book_size_field[book_new->field]++;//相关领域书数量+1
            book_data->tail = book_new;//链表元素+1
            display_book_pointer(book_new);
            printf("是否要继续? [1]是 [0]否\n");
            fflush(stdin);
        }
        else {
            fflush(stdin);
            printf("请重新输入指令\n");
            continue;
        }
    }
}
