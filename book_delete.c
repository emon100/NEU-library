/*制作人：贾浩楠
 * 函数功能：删除某项图书信息
 */

#include"lib.h"
//TODO:111111
void book_delete(book_list*book_data){
    int     code            =0;
    book    *head;
    book    *book_current;
    book    *book_last;
    //信息输入
    printf("Please input the book_code:");
    scanf("%d",&code);//获得要修改书的条码

    //书本匹配
    book_current=head=book_data->head;
    while(book_current->code!=code)
    {
        book_last=book_current;
        book_current=book_current->next;
    }//匹配书籍条码，获得删除书籍的指针

    //重连链表
    book_last->next=book_current->next;

    //book_list信息修改
    book_data->size-1;//总数修改
    book_data->book_size_field[book_current->field]-1;//相关领域数修改
}

