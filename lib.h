/*
 *图书管理系统头文件
 *主要内容:
 *包含需要的头文件
 *定义数据类型
 *要用的函数的原型
 */
#include <stdlib.h>
#include <stdio.h>
#include <strings>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>//时间头文件


#ifndef LIB_H_
#define LIB_H_
/*枚举变量，人员属性*/
enum PROPERTY{
   prop_reader,prop_administrator
};

/*枚举变量，书本领域*/
enum FIELD{
   science=0,literature,education,art,life
};

/*枚举变量，人物性别*/
enum SEX{
    male,female
};

/*枚举变量，登录状态*/
enum LOGIN_STATUS{
    no_user=-1,password_err=0,as_reader=1,as_admin=2
};

typedef struct BOOK {
    int             code;//条码
    char            book_name[100];
    char            author_name[200];
    char            press[50];
    enum FIELD      field;
    float           price;
    int             id_number;//借书者号码,-1代表没被借走
    int             date;//算一下这是一年中第几天吧
    struct BOOK     *next;
}book;

typedef struct BOOK_LIST {
    book            *head;
    book            *tail;
    int             code;//书籍条码
    int             size;//书本总量,可以用这个来记条码
    int             book_size_field[life+1];//各领域书籍数量
    int             book_borrowed;//借出书本总量
}book_list;

/*人员数据类型*/
typedef struct PERSON {
    int             id_number;//图书卡号码,请务必从1开始
    char            name[31];//姓名30位
    enum SEX        sex;
    char            password[13];//密码12位
    enum PROPERTY   prop;//人员属性
    int             borrow_quantity;//已借书籍数量
    int             book_id[10];//书籍条码，这个地方到时候改成书籍类型的指针以方便查找书籍
    float           penalty;//罚款
    struct PERSON   *next;//下一位人员地址
}person;//类型为person

/*人员链表的属性*/
typedef struct PERSON_LIST {
    int             size;//总人员个数
    int             id_number;//逐渐递增的图书卡号码，考虑到删除某个人之后size会变小有可能有重复的图书号码加上这项
    int             admin_size;//管理员个数，读者个数就直接相减就好了
    int             male_reader_size;
    person          *head;//人员链表第一个成员的地址
    person          *tail;//人员链表最后一个成员的地址
}person_list;

person *admin_init(void);
int login(int);
void information();
void readercenter();
void setting();
#endif
