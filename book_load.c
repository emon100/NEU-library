/*�����ˣ��ֺ��
 * �������ܣ����汾�γ�������ͼ����Ϣ
 */


#include"lib.h"
void book_load(book_list*book_data){
    book        *fp_book;
    book_list   *fp_list;
    book        *current=book_data->head;

    //book_list����
    fp_list=fopen("C:\\Users\\Monarcaa\\Desktop\\book_list.txt","wb+");//��ʼ��ȡͼ��������Ϣ
    fwrite(book_data,sizeof(book_list),1,fp_list);

    //book����
    fp_book=fopen("C:\\Users\\Monarcaa\\Desktop\\book.txt","wb+");//��ʼ��ȡͼ�����ݿ�
    for(int i=1;i<=book_data->size;i++){
        fwrite(current,sizeof(book),1,fp_book);
        current=current->next;
    }

    //�ļ��ر�
    fclose(fp_book);
    fclose(fp_list);

    //�ͷſռ�
    free(book_data);
}

