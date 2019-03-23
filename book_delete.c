/*制作人：贾浩楠
 * 函数功能：删除某项图书信息
 */

#include"lib.h"
void book_delete(book_list *book_data) {
    int         code = 0;
    int option;
    book        *book_previous;
    book        *book_delete;
    //信息输入
    printf("请输入要删除的书本名称:\n");
    scanf("%d", &code);//获得要修改书的条码
    fflush(stdin);

    //书本匹配
    book_delete =book_previous = book_data->head;

    if (book_delete==NULL) {
        printf("图书馆中没有书籍!\n");
        return;
    }

    //如果删头部
    if (book_delete->code == code) {
        printf("用户信息:\n");
        display_book_pointer(book_delete);
        printf("是否要继续删除? 输入 1 以继续:\n");
        option = getchar();
        fflush(stdin);
        if (option == '1') {
            book_data->head = book_delete->next;
            //进行判断修改总览
            book_data->size--;
            book_data->book_size_field[book_delete->field]--;
            free(book_delete);
            printf("删除完成\n");
        }
        else {
            printf("删除失败.正在返回...\n");
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
            printf("用户信息:\n");
            display_book_pointer(book_delete);
            printf("是否要继续删除? 输入 1 以继续, 输入其他内容以取消此次操作:\n");
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
                printf("删除失败.正在返回...\n");
                return;
            }
        }
        else {
            printf("没有找到您要删除的数据\n");
            return;
        }
    }
}

