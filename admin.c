//
// Created by emon100 on 2019/3/8 0008.
//
#include "lib.h"


person *admin_init(void){
    person *admin=(person *)malloc(sizeof(person));
    admin->id_number=1;
    strcpy(admin->name,"admin");
    strcpy(admin->password,"pass");
    admin->prop=administrator;
    person *reader=admin->next=(person*)malloc(sizeof(person));
    reader->id_number=100;
    strcpy(reader->name,"emon");
    strcpy(reader->password,"123");
    reader->prop=readerlv1;
    reader->next=NULL;
    return admin;
}
