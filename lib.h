/*
 *ͼ�����ϵͳͷ�ļ�
 *��Ҫ����:
 *������Ҫ��ͷ�ļ�
 *������������
 *Ҫ�õĺ�����ԭ��
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>//ʱ��ͷ�ļ�


#ifndef LIB_H_
#define LIB_H_

enum PROPERTY{
   prop_reader,prop_administrator
};

enum LOGIN_STATUS{
    no_user=-1,password_err=0,as_reader=1,as_admin=2
};
/*��Ա��������*/
typedef struct PERSON {
    int             id_number;//ͼ�鿨����
    char            name[31];//����30λ
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
    int             admin_size;//����Ա���������߸�����ֱ������ͺ���
    person          *head;//��Ա�����һ����Ա�ĵ�ַ
    person          *tail;//��Ա�������һ����Ա�ĵ�ַ
}p_list;

person *admin_init(void);
int login(int);
#endif
