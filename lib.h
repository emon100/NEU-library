/*
 * author:王一蒙
 *图书管理系统头文件
 *主要内容:
 *包含需要的头文件
 *定义数据类型
 *要用的函数的原型
 */
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>//时间头文件


#ifndef lib_h_
#define lib_h_


/*枚举变量，人员属性*/
enum property{
   prop_reader,prop_administrator
};

/*枚举变量，书本领域*/
enum field{
   science=0,literature,education,art,life
};

/*枚举变量，人物性别*/
enum sex{
    male,female
};

/*枚举变量，登录状态*/
enum login_status{
    no_user=-1,password_err=0,as_reader=1,as_admin=2
};

typedef struct book {
    int             code;//条码
    int             id_number;//借书者号码,-1代表没被借走
    char            book_name[100];
    char            author_name[200];
    char            press[50];
    enum field      field;
    float           price;
    time_t          borrow_time;//借书日期，时间类型变量，到时候用的时候可能都要取地址
    struct book     *next;
}book;

typedef struct book_list {
    book            *head;
    book            *tail;
    int             code;//书籍条码
    int             size;//书本总量,可以用这个来记条码
    int             book_size_field[life+1];//各领域书籍数量
    int             book_borrowed;//借出书本总量
}book_list;

/*人员数据类型*/
typedef struct person {
    int             id_number;//图书卡号码,请务必从1开始
    char            name[31];//姓名30位
    char            password[13];//密码12位
    enum sex        sex;
    enum property   prop;//人员属性
    int             borrow_quantity;//已借书籍数量
    int             book_id[10];//书籍条码，这个地方到时候改成书籍类型的指针以方便查找书籍
    float           penalty;//罚款
    struct person   *next;//下一位人员地址
}person;//类型为person

/*人员链表的属性*/
typedef struct person_list {
    int             size;//总人员个数
    int             id_number;//逐渐递增的图书卡号码，考虑到删除某个人之后size会变小有可能有重复的图书号码加上这项
    int             admin_size;//管理员个数，读者个数就直接相减就好了
    int             male_reader_size;
    person          *head;//人员链表第一个成员的地址
    person          *tail;//人员链表最后一个成员的地址
}person_list;

extern person              *current_user;//当前用户的用户节点地址

void            admin_init(person_list *);//测试函数
void            book_test(book_list *book_data);//测试函数


void user_init(person_list *);//读取用户文件创建用户链表
void book_init(book_list *);//读取书籍文件创建书籍链表


enum login_status        login(int,person_list *);//与正式版本不同的函数

void            information_reader(book_list *);//只能搜索书籍和查看普通图书馆数据
void            information_admin(book_list *,person_list *);//可以看所有图书馆数据，搜索图书和人员


void            reader_center(book_list *,person *);//读者系统
void            self_manage(book_list *,person *);
void            display_person(person *);//展示个人信息
void            display_book_pointer(book *);//根据书籍节点地址展示书籍信息
void            display_book_code(book_list *, int book_id);//根据书籍code展示书籍信息
void            borrow_book(book_list *,person *);
void            return_book(book_list *,person *);

void            manage(book_list *,person_list *);
void            person_edit(person_list *);
void            person_insert(person_list *);
void            person_delete(person_list *);
void            book_edit(book_list *);
void            book_insert(book_list *);

void            file_io(book_list *,person_list *);
void            backup(book_list *,person_list *);
void            recovery(book_list *,person_list *);
void            person_backup(person_list *);
void            person_recovery(person_list *);
void            book_backup(book_list *);
void            book_recovery(book_list *);


void            order_in_price(book_list *);
book            *search_book_pointer(int,book_list *);//搜索获得书节点地址，修改和搜索时可以使用,至于删除的话就还是遍历多情况讨论吧
person          *search_person_pointer(int,person_list *);//搜索获得借书者节点地址，同上
#endif
