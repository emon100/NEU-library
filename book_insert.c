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
    printf("You are adding new book.whether to continue or not? [1]Yes [0]No\n");
    fflush(stdin);
    while (1) {
        flag=getchar();
        fflush(stdin);
        if (flag=='0'){
            system("cls");
            break;
        }
        else if (flag=='1') {
            book_new->next = (book *) malloc(sizeof(book));//����book������
            book_new=book_new->next;
            book_new->code = book_data->code;

            printf("Please input the book's name:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->book_name, current);//ͼ����

            printf("Please input the authors' name:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->author_name, current);//������

            printf("Please input its press:\n");
            fflush(stdin);
            gets(current);
            fflush(stdin);
            strcpy(book_new->press, current);//������

            printf("Please choose its field:\n0.science\n1.literature\n2.education\n3.atr\n4.life\n");
            scanf("%d", &book_new->field);//����

            printf("Please input its price:\n");
            scanf("%f", &book_new->price);//�۸�

            book_new->id_number = -1;//�����ߺ���Ĭ��-1��ʾû�˽�

            //book_list��Ϣ�޸�
            book_new->next=NULL;
            book_data->size++;//�鱾����+1
            book_data->code = book_data->code + 1;//�鼮�������
            if(book_new->field<=life)
                book_data->book_size_field[book_new->field]++;//�������������+1
            book_data->tail = book_new;//����Ԫ��+1
            display_book_pointer(book_new);
            printf("whether to continue or not? [1]Yes [0]No\n");
            fflush(stdin);
        }
        else {
            fflush(stdin);
            printf("����������ָ��\n");
            continue;
        }
    }
}
