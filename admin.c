//
// Created by emon100 on 2019/3/8 0008.
//
#include "lib.h"


void admin_init(person_list *admin){
    admin->head=(person *)malloc(sizeof(person));
    admin->head->id_number=1;
    admin->head->sex=male;
    strcpy(admin->head->name,"admin");
    strcpy(admin->head->password,"pass");
    admin->head->prop=prop_administrator;
    admin->head->next=(person*)malloc(sizeof(person));
    admin->head->next->id_number=100;
    strcpy(admin->head->next->name,"emon");
    strcpy(admin->head->next->password,"123");
    admin->head->next->prop=prop_reader;
    admin->head->next->next=NULL;
}
