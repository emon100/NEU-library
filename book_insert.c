/*�����ˣ��ֺ��
 *�������ܣ�����鼮��Ϣ
 */

#include"lib.h"

void book_insert(book_list *book_data) {
    char current[201];
    int flag;
    book *book_new;
    book_new = book_data->tail;

    //book��Ϣ�޸�
    printf("���������һ���µ��鼮.�Ƿ�Ҫ����? [1]�� [0]��\n");
    fflush(stdin);
    while (1) {
        flag=getchar();
        fflush(stdin);
        if (flag=='0'){
            system("cls");
            break;
        }
        else if (flag=='1') {
            system("cls");
            book_new->next = (book *) malloc(sizeof(book));//����book������
            book_new=book_new->next;
            book_new->code = book_data->code;

            printf("�������鼮����:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->book_name, current);//ͼ����

            printf("��������������:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->author_name, current);//������

            printf("�����������:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->press, current);//������

            printf("��ѡ������:\n0.��ѧ\n1.��ѧ\n2.����\n3.����\n4.����\n");
            scanf("%d", &book_new->field);//����
            fflush(stdin);

            printf("������۸�:\n");
            scanf("%f", &book_new->price);//�۸�
            fflush(stdin);

            book_new->person_id_number = -1;//�����ߺ���Ĭ��-1��ʾû�˽�

            //book_list��Ϣ�޸�
            book_new->next=NULL;
            book_data->size++;//�鱾����+1
            book_data->code = book_data->code + 1;//�鼮�������
            if(book_new->field<=life)
                book_data->book_size_field[book_new->field]++;//�������������+1
            book_data->tail = book_new;//����Ԫ��+1
            display_book_pointer(book_new);
            printf("�Ƿ�Ҫ����? [1]�� [0]��\n");
            fflush(stdin);
        }
        else {
            fflush(stdin);
            printf("����������ָ��\n");
            continue;
        }
    }
}
