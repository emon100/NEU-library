/*�����ˣ��ֺ��
 *�������ܣ�����ͼ����Ϣ����
 */

#include"lib.h"
void chain_build(book_list *book_data){

    FILE        *fp_list;
    FILE        *fp_book;
    book        *head;
    book        *p1;
    book        *p2;//ͼ����Ϣ�ṹ��ָ��

    fp_book=fopen("C:\\Users\\Monarcaa\\Desktop\\book.txt","wb+");//��ʼ��ȡͼ�����ݿ�
    fp_list=fopen("C:\\Users\\Monarcaa\\Desktop\\book_list.txt","wb+");//��ʼ��ȡͼ��������Ϣ
    fread(book_data,sizeof(book_list),1,fp_list);
    head=(book*)malloc(book_data->size*sizeof(book));
    fread(p1,sizeof(book),1,fp_book);
    head=p1;
    for(int i=1;i<=book_data->size-1;i++){
        fread(p2,sizeof(book),1,fp_book);
        p1->next=p2;
        p1=p2;
    }
    p1->next=NULL;//��ȡ�鱾����

    book_data->head=head;
    book_data->tail=p2;//book_list��ַ

    fclose(fp_book);
    fclose(fp_list);
}
