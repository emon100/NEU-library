/*�����ˣ��ֺ��
 * �������ܣ�ɾ��ĳ��ͼ����Ϣ
 */

#include"lib.h"
//TODO:111111
void book_delete(book_list *book_data) {
    int code = 0;
    book *head;
    book *book_current;
    book *book_last;
    //��Ϣ����
    printf("Please input the book_code:\n");
    scanf("%d", &code);//���Ҫ�޸��������
    fflush(stdin);

    //�鱾ƥ��
    book_current = head = book_data->head;
    //�����ͷ���鱾
    if (book_current->code == code) {
        book_data->head = book_current->next;
        free(book_current);
    }
    else {
        while (book_current->code != code && book_current != NULL) {
            book_last = book_current;
            book_current = book_current->next;
        }//ƥ���鼮���룬���ɾ���鼮��ָ��
        //��������
        if(book_current->code==code) {
            book_last->next = book_current->next;
            //book_list��Ϣ�޸�
            book_data->size--;//�����޸�
            book_data->book_size_field[book_current->field]--;//����������޸�
            free(book_current);
            printf("Delete complete!\n");
            fflush(stdin);
            getchar();
            fflush(stdin);
        }
        else{
            printf("Book not found!\n");
            return;
        }
    }
}
