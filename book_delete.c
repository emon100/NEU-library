/*�����ˣ��ֺ��
 * �������ܣ�ɾ��ĳ��ͼ����Ϣ
 */

#include"lib.h"
//TODO:111111
void book_delete(book_list*book_data){
    int     code            =0;
    book    *head;
    book    *book_current;
    book    *book_last;
    //��Ϣ����
    printf("Please input the book_code:");
    scanf("%d",&code);//���Ҫ�޸��������

    //�鱾ƥ��
    book_current=head=book_data->head;
    while(book_current->code!=code)
    {
        book_last=book_current;
        book_current=book_current->next;
    }//ƥ���鼮���룬���ɾ���鼮��ָ��

    //��������
    book_last->next=book_current->next;

    //book_list��Ϣ�޸�
    book_data->size-1;//�����޸�
    book_data->book_size_field[book_current->field]-1;//����������޸�
}

