/*制作人：贾浩楠
 * 函数功能：储存本次程序运行图书信息
 */


#include"lib.h"
void book_backup(book_list *book_data){
    FILE        *fp_book;
    FILE        *fp_list;
    book        *current=book_data->head;
    //book_list储存
    if((fp_list = fopen("D:\\book_list.dat","wb+"))==NULL){
        printf("无法打开文件\n");
        return;
    }
    fwrite(book_data,sizeof(book_list),1,fp_list);
    fclose(fp_list);

    //book储存
    if((fp_book = fopen("D:\\book_data.dat","wb+"))==NULL){
        printf("无法打开文件\n");
        return;
    }
    while(current != NULL){
        fwrite(current,sizeof(book),1,fp_book);
        current=current->next;
    }
    //文件关闭
    fclose(fp_book);
}

