/*制作人：贾浩楠
 * 函数功能：储存本次程序运行图书信息
 */


#include"lib.h"
void book_load(book_list*book_data){
    book        *fp_book;
    book_list   *fp_list;
    book        *current=book_data->head;

    //book_list储存
    fp_list=fopen("C:\\Users\\Monarcaa\\Desktop\\book_list.txt","wb+");//开始读取图书链表信息
    fwrite(book_data,sizeof(book_list),1,fp_list);

    //book储存
    fp_book=fopen("C:\\Users\\Monarcaa\\Desktop\\book.txt","wb+");//开始读取图书数据库
    for(int i=1;i<=book_data->size;i++){
        fwrite(current,sizeof(book),1,fp_book);
        current=current->next;
    }

    //文件关闭
    fclose(fp_book);
    fclose(fp_list);

    //释放空间
    free(book_data);
}

