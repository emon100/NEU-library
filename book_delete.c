/*制作人：贾浩楠
 * 函数功能：删除某项图书信息
 */

#include"lib.h"
void book_delete(book_list *book_data) {
    int         code = 0;
    char        option;
    book        *book_previous;
    book        *book_delete;
    //信息输入
    printf("Please input the book_code:\n");
    scanf("%d", &code);//获得要修改书的条码
    fflush(stdin);

    //书本匹配
    book_delete =book_previous = book_data->head;

    if (book_delete==NULL) {
        printf("No book in library!\n");
        return;
    }

    //如果删头部
    if (book_delete->code == code) {
        printf("User info:\n");
        display_book_pointer(book_delete);
        printf("Still delete? Press 1 to continue:\n");
        option = getchar();
        fflush(stdin);
        if (option == '1') {
            book_data->head = book_delete->next;
            //进行判断修改总览
            book_data->size--;
            book_data->book_size_field[book_delete->field]--;
            free(book_delete);
            printf("Delete finished\n");
        }
        else {
            printf("Delete aborted. Returning\n");
            return;
        }
    }
        //如果非头部
    else {
        book_delete=book_delete->next;
        if(book_delete==NULL){
            printf("没有找到您要删除的数据\n");
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
            printf("没有找到您要删除的数据\n");
            return;
        }
        else if (book_delete->code == code) {
            printf("User info:\n");
            display_book_pointer(book_delete);
            printf("Still delete? Press 1 to continue, press another key to abort:\n");
            option = getchar();
            fflush(stdin);
            if (option == '1') {
                book_previous->next = book_delete->next;
                //如果是尾部那么修改尾部
                if(book_delete==book_data->tail)
                    book_data->tail=book_previous;
                //进行判断修改总览
                book_data->size--;
                book_data->book_size_field[book_delete->field]--;
                free(book_delete);
                printf("Delete finished!\n");
            }
            else {
                printf("Delete aborted. Returning...\n");
                return;
            }
        }
        else {
            printf("没有找到您要删除的数据\n");
            return;
        }
    }
}

