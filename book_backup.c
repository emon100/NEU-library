/*�����ˣ��ֺ��
 * �������ܣ����汾�γ�������ͼ����Ϣ
 */


#include"lib.h"
void book_backup(book_list *book_data){
    FILE        *fp_book;
    FILE        *fp_list;
    book        *current=book_data->head;
    //book_list����
    if((fp_list = fopen("D:\\book_list.dat","wb+"))==NULL){
        printf("�޷����ļ�\n");
        return;
    }
    fwrite(book_data,sizeof(book_list),1,fp_list);
    fclose(fp_list);

    //book����
    if((fp_book = fopen("D:\\book_data.dat","wb+"))==NULL){
        printf("�޷����ļ�\n");
        return;
    }
    while(current != NULL){
        fwrite(current,sizeof(book),1,fp_book);
        current=current->next;
    }
    //�ļ��ر�
    fclose(fp_book);
}

