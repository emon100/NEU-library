/*制作人：贾浩楠
 *函数功能：创建图书信息链表
 */

#include"lib.h"
void book_recovery(book_list *book_data){
    int         size;
    FILE        *fp_book;
    book        *book_pointer,*book_new;
    if((fp_book=fopen("D:\\book_list.dat","rb+"))==NULL){
        printf("无法打开文件\n");
        return;
    }//开始读取图书总览信息

    fread(book_data,sizeof(book_list),1,fp_book);
    fclose(fp_book);

    if((fp_book=fopen("D:\\book_data.dat","rb+"))==NULL){
        printf("无法打开文件\n");
        return;
    }//开始读取图书链表信息
    size=book_data->size;
    for(int i=0;i<size;++i){
        book_new=(book *)malloc(sizeof(book));
        if(i==0)book_data->head=book_new;
        else book_pointer->next=book_new;
        fread(book_new, sizeof(book),1,fp_book);
        book_pointer=book_new;
    }
    fclose(fp_book);
    book_pointer->next=NULL;
    book_data->tail=book_pointer;//尾部添加
}
