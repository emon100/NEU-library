#include "lib.h"

void person_recovery(person_list *person_data){
    FILE            *f_pointer;
    int             size;//��Ա����
    person          *person_pointer,*person_new;
    //��ȡ������Ϣ
    if((f_pointer = fopen("D:\\person_list.dat","rb+"))==NULL){
        printf("Can't open person_list!\n");
        return;
    }
    fread(person_data, sizeof(person_list),1,f_pointer);
    fclose(f_pointer);
    if((f_pointer = fopen("D:\\person_data.dat","rb+"))==NULL){
        printf("�޷����ļ�\n");
        return;
    }
    size=person_data->size;
    for(int i=0;i<size;++i){
        person_new=(person *)malloc(sizeof(person));
        if(i==0)person_data->head=person_new;
        else person_pointer->next=person_new;
        fread(person_new, sizeof(person),1,f_pointer);
        person_pointer=person_new;
    }
    fclose(f_pointer);
    person_pointer->next=NULL;
    person_data->tail=person_pointer;//β�����
}
