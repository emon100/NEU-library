/*
 *图书管理系统头文件
 *主要内容:
 *包含需要的头文件
 *定义数据类型
 *定义宏
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum PROPERTY{
   administrator,readerlv1,readerlv2,readerlv3
};

/*人员数据类型*/
typedef struct PERSON {
    int             id_number;//图书卡号码
    char            name[31];//姓名30位
    char            password[13];//密码12位
    enum PROPERTY   prop;//人员属性
    int             burrow_quantity;//已借书籍数量
    int             book_id[50];//书籍条码，这个地方到时候改成书籍类型的指针以方便查找书籍
    float           penalty;//罚款
    struct PERSON   *next;//下一位人员地址
}person;//类型为person

/*人员链表的属性*/
typedef struct PERSON_LIST {
    int             size;//总人员个数
    int             admin_size;//管理员个数，读者个数就直接相减就好了
    person          *head;//人员链表第一个成员的地址
    person          *tail;//人员链表最后一个成员的地址
}p_list;

