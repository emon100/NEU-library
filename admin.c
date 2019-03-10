//
// Created by emon100 on 2019/3/8 0008.
//
#include "lib.h"


person *admin_init(void){
    person *admin=(person *)malloc(sizeof(person));
    admin->id_number=1;
    admin->sex=male;
    strcpy(admin->name,"admin");
    strcpy(admin->password,"pass");
    admin->prop=prop_administrator;
    person *reader=admin->next=(person*)malloc(sizeof(person));
    reader->id_number=100;
    strcpy(reader->name,"emon");
    strcpy(reader->password,"123");
    reader->prop=prop_reader;
    reader->next=NULL;
    return admin;
}
