#include"lib.h"

void person_order_in_name(person_list *person_data) {
    person          *former;
    person          *current;
    person          *c_next;

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
}
