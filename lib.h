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


#ifndef lib_h_
#define lib_h_


/*ö�ٱ�������Ա����*/
enum property{
   prop_reader,prop_administrator
};

/*ö�ٱ������鱾����*/
enum field{
   science=0,literature,education,art,life
};

/*ö�ٱ����������Ա�*/
enum sex{
    male,female
};

/*ö�ٱ�������¼״̬*/
enum login_status{
    no_user=-1,password_err=0,as_reader=1,as_admin=2
};

typedef struct book {
    int             code;//����
    int             id_number;//�����ߺ���,-1����û������
    char            book_name[100];
    char            author_name[200];
    char            press[50];
    enum field      field;
    float           price;
    time_t          borrow_time;//�������ڣ�ʱ�����ͱ�������ʱ���õ�ʱ����ܶ�Ҫȡ��ַ
    struct book     *next;
}book;

typedef struct book_list {
    book            *head;
    book            *tail;
    int             code;//�鼮����
    int             size;//�鱾����,�����������������
    int             book_size_field[life+1];//�������鼮����
    int             book_borrowed;//����鱾����
}book_list;

/*��Ա��������*/
typedef struct person {
    int             id_number;//ͼ�鿨����,����ش�1��ʼ
    char            name[31];//����30λ
    char            password[13];//����12λ
    enum sex        sex;
    enum property   prop;//��Ա����
    int             borrow_quantity;//�ѽ��鼮����
    int             book_id[10];//�鼮���룬����ط���ʱ��ĳ��鼮���͵�ָ���Է�������鼮
    float           penalty;//����
    struct person   *next;//��һλ��Ա��ַ
}person;//����Ϊperson

/*��Ա���������*/
typedef struct person_list {
    int             size;//����Ա����
    int             id_number;//�𽥵�����ͼ�鿨���룬���ǵ�ɾ��ĳ����֮��size���С�п������ظ���ͼ������������
    int             admin_size;//����Ա���������߸�����ֱ������ͺ���
    int             male_reader_size;
    person          *head;//��Ա�����һ����Ա�ĵ�ַ
    person          *tail;//��Ա�������һ����Ա�ĵ�ַ
}person_list;

extern person              *current_user;//��ǰ�û����û��ڵ��ַ

void            admin_init(person_list *);//���Ժ���
void            book_test(book_list *book_data);//���Ժ���


void user_init(person_list *);//��ȡ�û��ļ������û�����
void book_init(book_list *);//��ȡ�鼮�ļ������鼮����


enum login_status        login(int,person_list *);//����ʽ�汾��ͬ�ĺ���

void            information_reader(book_list *);//ֻ�������鼮�Ͳ鿴��ͨͼ�������
void            information_admin(book_list *,person_list *);//���Կ�����ͼ������ݣ�����ͼ�����Ա


void            reader_center(book_list *,person *);//����ϵͳ
void            self_manage(book_list *,person *);
void            display_person(person *);//չʾ������Ϣ
void            display_book_pointer(book *);//�����鼮�ڵ��ַչʾ�鼮��Ϣ
void            display_book_code(book_list *, int book_id);//�����鼮codeչʾ�鼮��Ϣ
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
book            *search_book_pointer(int,book_list *);//���������ڵ��ַ���޸ĺ�����ʱ����ʹ��,����ɾ���Ļ��ͻ��Ǳ�����������۰�
person          *search_person_pointer(int,person_list *);//������ý����߽ڵ��ַ��ͬ��
#endif
