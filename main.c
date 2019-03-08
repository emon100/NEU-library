#include "library.h"

//测试用链表函数，真正使用的时候第一步就是读取人员文件登录

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

int login(int user_id){
    //测试登录
    person              *p1         =admin_init();
    int                 validity    =0;
    char *password_tmp=(char *)malloc(sizeof(char)*13);
    while(1){
        if(user_id==p1->id_number){
            switch(p1->prop){
                case administrator:     validity=2;break;
                case readerlv1    :     ;
                case readerlv2    :     ;
                case readerlv3    :     validity=1;break;
            }
            printf("%s,请输入密码:\n",p1->name);//到时候肯定不应该出名字
            scanf("%s",password_tmp);
            if(strcmp(p1->password,password_tmp)==0){
                free(password_tmp);
                return validity;
            else    return 0;
        }
        else continue;
        if(p1->next==NULL)
            break;
        else        p1=p1->next;
    }
    free(password_tmp);
    return             -1;
}

int main(void) {
    int                 user_id;//当前用户id
    int                 validity=1;//有效性0为密码错误，-1为找不到人，1为任何读者，2为管理员
    printf("欢迎使用图书管理系统，请先登录!\n");
    scanf("%d", &user_id);
    validity=login(user_id);
    if(validity>0){
        printf("*欢迎使用图书管理系统，请输入数字选择你需要的功能*\n"
           "*功能：[1]查询统计    [2]读者系统                *\n");
        if(validity==1)printf("reader");
        if(validity==2)printf("admin");
    }
    else if(validity==0)printf("密码错误");
    else printf("无此用户\n");
}
