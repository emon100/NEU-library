/*�����ˣ��ֺ��
 * �������ܣ��޸�ͼ����Ϣ
 */

#include"lib.h"
void book_edit(book_list *book_data) {
    int         code = 0;
    int         exit_flag;
    book        *book_current;
    int         choice = 0;
    char        current[200];
    while (1) {
        //��Ϣ����
        printf("Please input the book_code:\n");
        scanf("%d", &code);//���Ҫ�޸��������
        fflush(stdin);
        system("cls");
        //�鱾ƥ��
        book_current = book_data->head;
        while (book_current->code != code&&book_current!=NULL)book_current = book_current->next;//ƥ���鼮���룬������޸��鼮��ָ��
        //��Ϣ�޸�
        //�����޸�
        if (book_current->code == code) {
            display_book_pointer(book_current);
            printf("Please choose the information you want to change\n");
            printf("1.book_name\n2.author_name\n3.press\n4.field\n5.price\n");
            scanf("%d", &choice);
            fflush(stdin);
            while (1){
                if(exit_flag!=1){
                    choice=getchar();
                    fflush(stdin);
                    switch (choice) {
                        case 1: {
                            printf("Please input new book_name:\n");
                            gets(current);
                            strcpy(book_current->book_name, current);
                            break;
                        }//ͼ�����޸�

                        case 2: {
                            printf("Please input new author_name:\n");
                            gets(current);
                            strcpy(book_current->author_name, current);
                            break;
                        }//�������޸�

                        case 3: {
                            printf("Please input new press:\n");
                            gets(current);
                            strcpy(book_current->press, current);
                            break;
                        }//�������޸�

                        case 4: {
                            book_data->book_size_field[book_current->field]--;
                            printf("Please input new field:\n");
                            scanf("%d", &book_current->field);
                            if(book_current->field<=life)
                                book_data->book_size_field[book_current->field]++;//�������䶯
                            break;
                        }

                        case 5: {
                            printf("Please input new price:\n");
                            scanf("%f", &book_current->price);
                            break;
                        }

                        default:
                            printf("Input error!Please enter again:\n");
                            break;
                    }
                }
                system("cls");
                display_book_pointer(book_current);
                if(exit_flag==1)printf("Input error, please enter again:\n");
                exit_flag=0;
                //ѯ���Ƿ����
                printf("whether to continue or not�� [0]No  [1]Yes [2]Manage another Book\n");
                choice=getchar();
                system("cls");
                fflush(stdin);
                if (choice== '0') {
                    return;
                }
                else if (choice== '1') {
                    display_book_pointer(book_current);
                    printf("Please choose the information you want to change\n");
                    printf("1.book_name\n2.author_name\n3.press\n4.field\n5.price\n");
                    continue;
                }
                else if (choice=='2'){
                    system("cls");
                    break;
                }
                else {
                    system("cls");
                    exit_flag=1;
                    continue;
                }
            }
        }
        else {
            system("cls");
            printf("Book not Found!\n");
            break;
        }
    }
}

