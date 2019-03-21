#include"lib.h"

void person_order_in_id_number(person_list *person_data) {
    person          *former;
    person          *current;
    person          *c_next;

    if (person_data->size <= 1);
    else{
        for(int i = 1; i <= person_data->size - 1; ++i){
            current = person_data->head;
            c_next  = current->next;                    //��current��c_next��ʼ��

            if(current->id_number > c_next->id_number){ //����λ�ý��������
                current->next = c_next->next;           //ǰ�ߵ�β����Ϊ���ߵ�β��
                c_next->next  = current;                //���ߵ�β����Ϊǰ�ߵĵ�ַ
                person_data->head = c_next;             //ͬʱ���ߵĵ�ַ��Ϊ����ͷ��ַ
                former = c_next;                        //��c_next�ĵ�ַ������former��
                c_next = current->next;                 //**����**
            }

            else{                                       //����λ��û�з������������
                former = current;                       //��c_next�ĵ�ַ������former��
                current = current->next;
                c_next = c_next->next;                  //����
            }

            for (int j = 3; j <= person_data->size; ++j) {
                if (current->id_number > c_next->id_number) {   //����λ�ý��������
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
