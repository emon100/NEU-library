/*�����ˣ��ֺ��
 * �������ܣ��޸�ͼ����Ϣ
 */

#include"lib.h"
void book_edit(book_list *book_data) {
    int         code = 0;
    int         exit_flag=0,ok;
    book        *book_current;
    int         choice = 0;
    char        current[200];
    while (1) {
        ok=0;
        //��Ϣ����
        printf("�������鱾����:\n");
        scanf("%d", &code);//���Ҫ�޸��������
        fflush(stdin);
        system("cls");
        //�鱾ƥ��
        book_current=search_book_pointer(code,book_data);
        if (book_current==NULL) {
            system("cls");
            printf("��δ�ҵ��Ȿ��!\n");
            return;
        }
        //��Ϣ�޸�
        //�����޸�
        else if (book_current->code == code) {
            display_book_pointer(book_current);
            printf("������ָ���Ը��������޸ĵ��鼮��Ϣ:\n");
            printf("[1]�鼮����\n[2]��������\n[3]������\n[4]�鼮����\n[5]�鼮�۸�\n[6]�����ϼ��˵�\n");
            fflush(stdin);
            while (1){
                if(exit_flag!=1){
                    choice=getchar();
                    fflush(stdin);
                    switch (choice) {
                        case '1': {
                            printf("�������µ��鼮����:\n");
                            while(!ok){
                                gets(current);
                                if(strlen(current)>99){
                                    printf("\n���ݹ���,���������룺");
                                }
                                else ok=1;
                            }
                            ok=0;
                            fflush(stdin);
                            strcpy(book_current->book_name, current);
                            break;
                        }//ͼ�����޸�

                        case '2': {
                            printf("�������µ���������:\n");
                            while(!ok){
                                gets(current);
                                if(strlen(current)>199){
                                    printf("\n���ݹ���,���������룺");
                                }
                                else ok=1;
                            }
                            ok=0;
                            fflush(stdin);
                            strcpy(book_current->author_name, current);
                            break;
                        }//�������޸�

                        case '3': {
                            printf("�������µĳ�����:\n");
                            while(!ok){
                                gets(current);
                                if(strlen(current)>49){
                                    printf("\n���ݹ���,���������룺");
                                }
                                else ok=1;
                            }
                            ok=0;
                            fflush(stdin);
                            strcpy(book_current->press, current);
                            break;
                        }//�������޸�

                        case '4': {
                            book_data->book_size_field[book_current->field]--;
                            printf("�������µ��鼮����:\n");
                            printf("0.��ѧ\n1.��ѧ\n2.����\n3.����\n4.����\n");
                            scanf("%d", &book_current->field);
                            fflush(stdin);
                            if(book_current->field<=life)
                                book_data->book_size_field[book_current->field]++;//�������䶯
                            break;
                        }

                        case '5': {
                            printf("�������µ��鼮�۸�:\n");
                            scanf("%f", &book_current->price);
                            fflush(stdin);
                            break;
                        }

                        case '6': {
                            system("cls");
                            fflush(stdin);
                            return;
                        }

                        default:
                            fflush(stdin);
                            printf("�������!����������:\n");
                            break;
                    }
                }
                system("cls");
                display_book_pointer(book_current);
                if(exit_flag==1)printf("�������!����������:\n");
                exit_flag=0;
                //ѯ���Ƿ����
                printf("�Ƿ�Ҫ������ [0]��  [1]�� [2]������һ���鼮\n");
                choice=getchar();
                system("cls");
                fflush(stdin);
                if (choice== '0') {
                    return;
                }
                else if (choice== '1') {
                    display_book_pointer(book_current);
                    printf("������ָ���Ը��������޸ĵ��鼮��Ϣ:\n");
                    printf("[1]�鼮����\n[2]��������\n[3]������\n[4]�鼮����\n[5]�鼮�۸�\n[6]�����ϼ��˵�\n");
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
            printf("��δ�ҵ��Ȿ�鼮!\n");
            return;
        }
    }
}

