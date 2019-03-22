#include"lib.h"

void book_order_in_price(book_list *book_data) {
    book           *former;
    book           *current;
    book           *c_next;
    book           *p_book;

    if (book_data->size <= 1);
    else {
        for (int i = 1; i <= book_data->size - 1; ++i) {
            current=book_data->head;
            c_next=current->next;

            if (current->price > c_next->price) {
                current->next = c_next->next;//ǰ�ߵ�β����Ϊ���ߵ�β��
                c_next->next = current;//���ߵ�β����Ϊǰ�ߵĵ�ַ
                book_data->head = c_next;//******
                former=c_next;
                c_next = current->next;
            }//��һ���͵ڶ������򣬱���head

            else{
                former=current;
                current=current->next;
                c_next=c_next->next;
            }

            if(book_data->size==2)break;

            for (int j = 0; j <= book_data->size-3; ++j) {
                if (current->price > c_next->price) {
                    current->next = c_next->next;//ǰ�ߵ�β����Ϊ���ߵ�β��
                    c_next->next = current;//���ߵ�β����Ϊǰ�ߵĵ�ַ
                    former->next=c_next;
                    former=c_next;
                    c_next = current->next;//����
                }//��С��������
                else {
                    former=current;
                    current = current->next;
                    c_next = c_next->next;
                }//����
            }
        }
    }
    p_book = book_data->head;
    while (p_book != NULL) {
        printf("|Title:%-30s|Author:%-20s|Press:%-20s|Code:%d\n", p_book->book_name, p_book->author_name, p_book->press,p_book->code);
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
