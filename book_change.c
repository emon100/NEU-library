/*�����ˣ��ֺ��
 * �������ܣ��޸�ͼ����Ϣ
 */

#include"lib.h"
void book_change(book_list*book_data){
    int     code            =0;
    book    *head;
    book    *book_current;
    int     choice          =0;
    char    current[200];
    char    a;

    //��Ϣ����
    printf("Please input the book_code:");
    scanf("%d",&code);//���Ҫ�޸��������

    //�鱾ƥ��
    book_current=head=book_data->head;
    while(book_current->code!=code)book_current=book_current->next;//ƥ���鼮���룬������޸��鼮��ָ��

    //��Ϣ�޸�
        //�����޸�
        printf("Please choose the information you want to change");
        printf("1.book_name\n2.author_name\n3.press\n4.field\n5.price\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Please input new book_name:");
                scanf("%s", current);
                strcpy(book_current->book_name, current);
                break;
            }//ͼ�����޸�

            case 2: {
                printf("Please input new author_name:");
                scanf("%s", current);
                strcpy(book_current->author_name, current);
                break;
            }//�������޸�

            case 3: {
                printf("Please input new press:");
                scanf("%s", current);
                strcpy(book_current->press, current);
                break;
            }//�������޸�

            case 4: {
                book_data->book_size_field[book_current->field]-1;
                printf("Please input new field:");
                scanf("%d", &book_current->field);
                book_data->book_size_field[book_current->field]+1;//�������䶯
                break;
            }

            case 5: {
                printf("Please input new price:");
                scanf("%f", &book_current->price);
                break;
            }

            default:
                printf("Please input the right number!");
        }

        //ѭ���޸�
        while(1){
            printf("Do you want to continue?\nPlease input Y to continue or else to exit");
            scanf("%c",&a);
            if(a=='Y'){printf("Please choose the information you want to change");
            printf("1.book_name\n2.author_name\n3.press\n4.field\n5.price\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    printf("Please input new book_name:");
                    scanf("%s", current);
                    strcpy(book_current->book_name, current);
                    break;
                }//ͼ�����޸�

                case 2: {
                    printf("Please input new author_name:");
                    scanf("%s", current);
                    strcpy(book_current->author_name, current);
                    break;
                }//�������޸�

                case 3: {
                    printf("Please input new press:");
                    scanf("%s", current);
                    strcpy(book_current->press, current);
                    break;
                }//�������޸�

                case 4: {
                    book_data->book_size_field[book_current->field]-1;
                    printf("Please input new field:");
                    scanf("%d", &book_current->field);
                    book_data->book_size_field[book_current->field]+1;//�������䶯
                    break;
                }

                case 5: {
                    printf("Please input new price:");
                    scanf("%f", &book_current->price);
                    break;
                }

                default:
                    printf("Please input the right number!");
            }}//Y�� �����޸�
            else break;//������ �˳�����
        }
    }


