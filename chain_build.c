/*制作人：贾浩楠
 *函数功能：创建图书信息链表
 */

#include"lib.h"
void chain_build(book_list *book_data){

    FILE        *fp_list;
    FILE        *fp_book;
    book        *head;
    book        *p1;
    book        *p2;//图书信息结构体指针

    fp_book=fopen("C:\\Users\\Monarcaa\\Desktop\\book.txt","wb+");//开始读取图书数据库
    fp_list=fopen("C:\\Users\\Monarcaa\\Desktop\\book_list.txt","wb+");//开始读取图书链表信息
    fread(book_data,sizeof(book_list),1,fp_list);
    head=(book*)malloc(book_data->size*sizeof(book));
    fread(p1,sizeof(book),1,fp_book);
    head=p1;
    for(int i=1;i<=book_data->size-1;i++){
        fread(p2,sizeof(book),1,fp_book);
        p1->next=p2;
        p1=p2;
    }
    p1->next=NULL;//读取书本数据

    book_data->head=head;
    book_data->tail=p2;//book_list地址

    fclose(fp_book);
    fclose(fp_list);
}
