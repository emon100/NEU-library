#include"lib.h"
void person_backup(person_list *person_data){
    FILE                *f_pointer;
    person              *person_pointer=person_data->head;
    //��д������Ϣ
    if((f_pointer = fopen("D:\\person_list.dat","wb+"))==NULL){
        printf("�޷����ļ�\n");
        return;
    }
    fwrite(person_data, sizeof(person_list),1,f_pointer);
    fclose(f_pointer);
    //д��ڵ�
    if((f_pointer = fopen("D:\\person_data.dat","wb+"))==NULL){
        printf("�޷����ļ�\n");
        return;
    }
    while(person_pointer != NULL){
        fwrite(person_pointer, sizeof(person),1,f_pointer);
        person_pointer = person_pointer->next;
    }
    fclose(f_pointer);
}

