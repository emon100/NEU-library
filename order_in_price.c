#include"lib.h"
void order_in_price(book_list *book_data){
    book    *former;
    book    *current;
    book    *cnext;
    book    *p_book;

    current =book_data->head;
    cnext   =current->next;
    for(int i=1;i<=book_data->size-1;++i){
    if(current->price>cnext->price){
        former=cnext;//�洢ԭ��������Ϣ
        current->next=former->next;//ǰ�ߵ�β����Ϊ���ߵ�β��
        cnext->next=current;//���ߵ�β����Ϊǰ�ߵĵ�ַ
        book_data->head=cnext;//******
        cnext=current->next;
    }//��һ���͵ڶ������򣬱���head

    for(int i=3;i<=book_data->size;++i)
    {
    if(current->price>cnext->price){
        former=cnext;//�洢ԭ��������Ϣ
        current->next=former->next;//ǰ�ߵ�β����Ϊ���ߵ�β��
        cnext->next=current;//���ߵ�β����Ϊǰ�ߵĵ�ַ
        cnext=current->next;//����
    }//��С��������
    else{
    current=current->next;
    cnext=cnext->next;}//����
    }}

    p_book=book_data->head;
    do {
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
        p_book=p_book->next;
    }while(p_book->next=NULL);//����鼮��Ϣ
}
