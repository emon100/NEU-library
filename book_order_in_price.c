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
                current->next = c_next->next;//前者的尾部变为后者的尾部
                c_next->next = current;//后者的尾部变为前者的地址
                book_data->head = c_next;//******
                former=c_next;
                c_next = current->next;
            }//第一个和第二个排序，保留head

            else{
                former=current;
                current=current->next;
                c_next=c_next->next;
            }

            if(book_data->size==2)break;

            for (int j = 0; j <= book_data->size-3; ++j) {
                if (current->price > c_next->price) {
                    current->next = c_next->next;//前者的尾部变为后者的尾部
                    c_next->next = current;//后者的尾部变为前者的地址
                    former->next=c_next;
                    former=c_next;
                    c_next = current->next;//后移
                }//从小到大排序
                else {
                    former=current;
                    current = current->next;
                    c_next = c_next->next;
                }//后移
            }
        }
    }
    p_book = book_data->head;
    while (p_book != NULL) {
        printf("|标题:%-30s\n|作者:%-20s|出版社:%-20s|编码:%d\n", p_book->book_name, p_book->author_name, p_book->press,p_book->code);
        printf("|领域:");
        switch (p_book->field) {
            case science:
                printf("科学");
                break;
            case literature:
                printf("文学");
                break;
            case education:
                printf("教育");
                break;
            case art:
                printf("艺术");
                break;
            case life:
                printf("生活");
                break;
        }
        printf("         |Price:%6.2f\n\n", p_book->price);
        p_book = p_book->next;
    }//输出书籍信息
}
