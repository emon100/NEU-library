#include "lib.h"

#define LEN sizeof(person)

void            fsh(void) {
    while ('\n' != getchar());
}

//借书者信息录入
person * add(person_list *status);
int main()
{
    person_list *person_info=(person_list *)malloc(sizeof(person_list));
    person      *person_pointer;
    add(person_info);
    person_pointer=person_info->head;
    do {
        printf("%5d %10s %12s %3d %3d\n",person_pointer->id_number,person_pointer->name,person_pointer->password,person_pointer->prop,person_pointer->penalty);
        if(person_pointer->next!=NULL)person_pointer=person_pointer->next;
        else break;
    }while(1);
}