#include"lib.h"

void person_order_in_name(person_list *person_data) {
    person          *former;
    person          *current;
    person          *c_next;
    person          *user;

    if (person_data->size <= 1);
    else{
        for(int i = 1; i <= person_data->size - 1; ++i){
            current = person_data->head;
            c_next  = current->next;

            if(strcmp(current->name , c_next->name)>0){
                current->next = c_next->next;
                c_next->next  = current;
                person_data->head = c_next;
                former = c_next;
                c_next = current->next;
            }

            else{
                former = current;
                current = current->next;
                c_next = c_next->next;
            }

            for (int j = 3; j <= person_data->size; ++j) {
                if (strcmp(current->name , c_next->name)>0) {   //����λ�ý��������
                    current->next = c_next->next;       //ǰ�ߵ�β����Ϊ���ߵ�β��
                    c_next->next = current;             //���ߵ�β����Ϊǰ�ߵĵ�ַ
                    former->next = c_next;              //���ӽڵ�
                    former=c_next;                      //��c_next�ĵ�ַ������former��
                    c_next = current->next;             //����
                }
                else {                                  //����λ��û�з������������
                    former = current;
                    current = current->next;
                    c_next = c_next->next;              //����
                }
            }
        }
    }
    user=person_data->head;

    while (user != NULL) {
        printf("\nUser's infomation:\n"
               "ID:%-5d|Name:%-10s|",user->id_number,user->name);
        printf("password:%-12s|",user->password);
        if(user->sex==male)printf("Sex:Male  |\n");
        else if(user->sex==female)printf("Sex:Female|\n");
        else printf("Sex:Error\n");
        if(user->prop==prop_reader)printf("Property:Reader         |");
        else if(user->prop==prop_administrator)printf("Property:Administrator  |");
        else printf("Property:Error  |");
        printf("Penalty:%6.2f       |",user->penalty);
        printf("Book borrowed:%-3d\n\n",user->borrow_quantity);
        user = user->next;
    }//�����Ա��Ϣ
    }

