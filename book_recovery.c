/*�����ˣ��ֺ��
 *�������ܣ�����ͼ����Ϣ����
 */

#include"lib.h"
void book_recovery(book_list *book_data){
    int         size;
    FILE        *fp_book;
    book        *book_pointer,*book_new;
    if((fp_book=fopen("D:\\book_list.dat","rb+"))==NULL){
        printf("�޷����ļ�\n");
        return;
    }//��ʼ��ȡͼ��������Ϣ

    fread(book_data,sizeof(book_list),1,fp_book);
    fclose(fp_book);

    if((fp_book=fopen("D:\\book_data.dat","rb+"))==NULL){
        printf("�޷����ļ�\n");
        return;
    }//��ʼ��ȡͼ��������Ϣ
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
    book_data->tail=book_pointer;//β�����
}
