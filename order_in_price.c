#include"lib.h"

void order_in_price(book_list *book_data) {
    book           *former;
    book           *current;
    book           *c_next;
    book           *p_book;

    if (book_data->size == 1);
    else {
        current = book_data->head;
        c_next = current->next;
        for (int i = 1; i <= book_data->size - 1; ++i) {
            if (current->price > c_next->price) {
                former = c_next;//�洢ԭ��������Ϣ
                current->next = former->next;//ǰ�ߵ�β����Ϊ���ߵ�β��
                c_next->next = current;//���ߵ�β����Ϊǰ�ߵĵ�ַ
                book_data->head = c_next;//******
                c_next = current->next;
            }//��һ���͵ڶ������򣬱���head

            else{
                current=current->next;
                c_next=c_next->next;
            }

            for (int j = 3; j <= book_data->size; ++j) {
                if (current->price > c_next->price) {
                    former = c_next;//�洢ԭ��������Ϣ
                    current->next = former->next;//ǰ�ߵ�β����Ϊ���ߵ�β��
                    c_next->next = current;//���ߵ�β����Ϊǰ�ߵĵ�ַ
                    c_next = current->next;//����
                }//��С��������
                else {
                    current = current->next;
                    c_next = c_next->next;
                }//����
            }
        }
    }
    p_book = book_data->head;
    while (p_book != NULL) {
        printf("|Title:%-30s|Author:%-20s|Press:%-20s\n", p_book->book_name, p_book->author_name, p_book->press);
        printf("|Field:");
        switch (p_book->field) {
            case science:
                printf("Science");
                break;
            case literature:
                printf("Literature");
                break;
            case education:
                printf("Education");
                break;
            case art:
                printf("Art");
                break;
            case life:
                printf("Life");
                break;
        }
        printf("         |Price:%6.2f\n", p_book->price);
        p_book = p_book->next;
    }//����鼮��Ϣ
}
