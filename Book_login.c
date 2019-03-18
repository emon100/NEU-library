/*制作人：贾浩楠
 *函数功能：添加书籍信息
 */

#include"lib.h"

void book_login(book_list*book_data){
    char current[100];

    book *p1;
    p1 = (book *) malloc(sizeof(book));//开辟book缓存区
    //book信息修改

    p1->code=book_data->code=book_data->code+1;//书籍条码

    printf("Please input the book's name:\n");
    scanf("%s", current);
    strcpy(p1->book_name, current);//图书名

    printf("Please input the author's name:\n");
    scanf("%s", current);
    strcpy(p1->author_name, current);//作者名

    printf("Please input its press:\n");
    scanf("%s", current);
    strcpy(p1->press, current);//出版社

    printf("Please choose its field:0.science\n1.literature\n2.education\n3.atr\n4.life\n");
    scanf("%d", &p1->field);//领域

    printf("Please input its price:\n");
    scanf("%f", &p1->price);//价格

    p1->id_number = -1;//借书者号码

    p1->date=0;//借书日期
    //book_list信息修改

    book_data->size++;//书本总量+1
    book_data->book_size_field[p1->field]++;//相关领域书记数量+1

    book_data->tail->next=p1;
    book_data->tail=p1;//链表元素+1

}

