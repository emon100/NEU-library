/*
 *ͼ�����ϵͳͷ�ļ�
 *��Ҫ����:
 *������Ҫ��ͷ�ļ�
 *������������
 *�����
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum PROPERTY{
   administrator,readerlv1,readerlv2,readerlv3
};

/*��Ա��������*/
typedef struct PERSON {
    int             id_number;//ͼ�鿨����
    char            name[31];//����30λ
    char            password[13];//����12λ
    enum PROPERTY   prop;//��Ա����
    int             burrow_quantity;//�ѽ��鼮����
    int             book_id[50];//�鼮���룬����ط���ʱ��ĳ��鼮���͵�ָ���Է�������鼮
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

