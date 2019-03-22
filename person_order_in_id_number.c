#include"lib.h"

void person_order_in_id_number(person_list *person_data) {
    person          *former;
    person          *current;
    person          *c_next;
    person          *user;

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

            if(person_data->size==2)break;

            for (int j = 0; j <= person_data->size-3; ++j) {
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
    user=person_data->head;

    while (user != NULL) {
        printf("\n�û���Ϣ:\n"
               "�˺�:%-5d|����:%-10s|",user->id_number,user->name);
        printf("����:%-12s|",user->password);
        if(user->sex==male)printf("�Ա�:����  |\n");
        else if(user->sex==female)printf("�Ա�:Ů��|\n");
        else printf("�Ա�:δ֪\n");
        if(user->prop==prop_reader)printf("����:����         |");
        else if(user->prop==prop_administrator)printf("����:����Ա       |");
        else printf("����:δ֪  |");
        printf("����:%6.2f       |",user->penalty);
        printf("��������:%-3d\n\n",user->borrow_quantity);
        user = user->next;
    }//�����Ա��Ϣ
}
