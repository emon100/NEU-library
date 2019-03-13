/*
 * author:��һ��
 *ͼ�����ϵͳͷ�ļ�
 *��Ҫ����:
 *������Ҫ��ͷ�ļ�
 *������������
 *Ҫ�õĺ�����ԭ��
 */
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>//ʱ��ͷ�ļ�


#ifndef LIB_H_
#define LIB_H_
/*ö�ٱ�������Ա����*/
enum PROPERTY{
   prop_reader,prop_administrator
};

/*ö�ٱ������鱾����*/
enum FIELD{
   science=0,literature,education,art,life
};

/*ö�ٱ����������Ա�*/
enum SEX{
    male,female
};

/*ö�ٱ�������¼״̬*/
enum LOGIN_STATUS{
    no_user=-1,password_err=0,as_reader=1,as_admin=2
};

typedef struct BOOK {
    int             code;//����
    char            book_name[100];
    char            author_name[200];
    char            press[50];
    enum FIELD      field;
    float           price;
    int             id_number;//�����ߺ���,-1����û������
    int             date;//��һ������һ���еڼ����
    struct BOOK     *next;
}book;

typedef struct BOOK_LIST {
    book            *head;
    book            *tail;
    int             code;//�鼮����
    int             size;//�鱾����,�����������������
    int             book_size_field[life+1];//�������鼮����
    int             book_borrowed;//����鱾����
}book_list;

/*��Ա��������*/
typedef struct PERSON {
    int             id_number;//ͼ�鿨����,����ش�1��ʼ
    char            name[31];//����30λ
    enum SEX        sex;
    char            password[13];//����12λ
    enum PROPERTY   prop;//��Ա����
    int             borrow_quantity;//�ѽ��鼮����
    int             book_id[10];//�鼮���룬����ط���ʱ��ĳ��鼮���͵�ָ���Է�������鼮
    float           penalty;//����
    struct PERSON   *next;//��һλ��Ա��ַ
}person;//����Ϊperson

/*��Ա���������*/
typedef struct PERSON_LIST {
    int             size;//����Ա����
    int             id_number;//�𽥵�����ͼ�鿨���룬���ǵ�ɾ��ĳ����֮��size���С�п������ظ���ͼ������������
    int             admin_size;//����Ա���������߸�����ֱ������ͺ���
    int             male_reader_size;
    person          *head;//��Ա�����һ����Ա�ĵ�ַ
    person          *tail;//��Ա�������һ����Ա�ĵ�ַ
}person_list;
void            fsh(void);
void            admin_init(person_list *);
int             login(int,person_list *);
void            information_reader(book_list *,person_list *);//ֻ�������鼮�Ͳ鿴��ͨͼ�������
void            information_admin(book_list *,person_list *);//���Կ�����ͼ������ݣ�����ͼ�����Ա
void            readercenter(book_list *,person_list *);
void            manage(book_list *,person_list *);
book            *search_book_pointer(int,book_list *);//���������ڵ��ַ���޸ĺ�����ʱ����ʹ��,����ɾ���Ļ��ͻ��Ǳ�����������۰�
person          *search_person_pointer(int,person_list *);//������ý����߽ڵ��ַ��ͬ��
#endif
