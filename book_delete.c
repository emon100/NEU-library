/*�����ˣ��ֺ��
 * �������ܣ�ɾ��ĳ��ͼ����Ϣ
 */

#include"lib.h"
void book_delete(book_list *book_data) {
    int         code = 0;
    int option;
    book        *book_previous;
    book        *book_delete;
    //��Ϣ����
    printf("������Ҫɾ�����鱾����:\n");
    scanf("%d", &code);//���Ҫ�޸��������
    fflush(stdin);

    //�鱾ƥ��
    book_delete =book_previous = book_data->head;

    if (book_delete==NULL) {
        printf("ͼ�����û���鼮!\n");
        return;
    }

    //���ɾͷ��
    if (book_delete->code == code) {
        printf("�û���Ϣ:\n");
        display_book_pointer(book_delete);
        printf("�Ƿ�Ҫ����ɾ��? ���� 1 �Լ���:\n");
        option = getchar();
        fflush(stdin);
        if (option == '1') {
            book_data->head = book_delete->next;
            //�����ж��޸�����
            book_data->size--;
            book_data->book_size_field[book_delete->field]--;
            free(book_delete);
            printf("ɾ�����\n");
        }
        else {
            printf("ɾ��ʧ��.���ڷ���...\n");
            return;
        }
    }
        //�����ͷ��
    else {
        book_delete=book_delete->next;
        if(book_delete==NULL){
            printf("û���ҵ���Ҫɾ��������\n");
            return;
        }
        else {
            while (book_delete->code != code) {
                book_delete = book_delete->next;
                book_previous = book_previous->next;
                if(book_delete==NULL)break;
            }
        }
        if(book_delete==NULL){
            printf("û���ҵ���Ҫɾ��������\n");
            return;
        }
        else if (book_delete->code == code) {
            printf("�û���Ϣ:\n");
            display_book_pointer(book_delete);
            printf("�Ƿ�Ҫ����ɾ��? ���� 1 �Լ���, ��������������ȡ���˴β���:\n");
            option = getchar();
            fflush(stdin);
            if (option == '1') {
                book_previous->next = book_delete->next;
                //�����β����ô�޸�β��
                if(book_delete==book_data->tail)
                    book_data->tail=book_previous;
                //�����ж��޸�����
                book_data->size--;
                book_data->book_size_field[book_delete->field]--;
                free(book_delete);
                printf("Delete finished!\n");
            }
            else {
                printf("ɾ��ʧ��.���ڷ���...\n");
                return;
            }
        }
        else {
            printf("û���ҵ���Ҫɾ��������\n");
            return;
        }
    }
}

