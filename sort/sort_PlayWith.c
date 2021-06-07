//
// Created by Matthew on 2021/6/7.
// ��ת���ݽṹ
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>


#define OK 1
#define Error 0
#define TRUE 1
#define FALSE 0

#define MAX_LENGTH_INSERT_SORT 7 /* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ */

typedef int Status; //�����Զ���ʹ��
#define MAXSIZE 10000  /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */

#define SWAP(a,b) \
do{\
	(a) ^= (b);\
	(b) ^= (a);\
	(a) ^= (b);\
}while(0)

typedef struct {
    int r[MAXSIZE+1]; /* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */
    int length;         /* ���ڼ�¼˳���ĳ��� */
}SqList;


void print(SqList L)
{
    int i;
    for (i = 1; i < L.length; i++) {
        printf("%d,", L.r[i]);
    }
    printf("%d", L.r[i]);
    printf("\n");
}


// ��������
void BubbleSort(SqList *L)
{
    int i, j;

    for ( i = 1; i < L->length; i++) {
        bool has_swap = false;
        for (j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j+1])
            {
                SWAP(L->r[j], L->r[j+1]);
                has_swap = true;
            }
        }
        if (!has_swap) break;
    }
}


/* ��˳���L����ѡ������ */
void select_sort(SqList *L)
{
    int i,j,min;
    for (i = 1; i < L->length; i++) {
        min = i;
        for (j = i+1; j <L->length ; ++j) { /* ѭ��֮������� */
            if (L->r[min] > L->r[j]) /* �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;            /* ���˹ؼ��ֵ��±긳ֵ��min */
        }
        if (i != min)
            SWAP(i, min);
    }
}

/**
 *  ��˳���L��ϣ������
 * @param L
 */
void shell_sort(SqList *L)
{
    int i, j, k = 0;
    int increment = L->length;
    do {
        increment = increment/3 + 1; /* ��������*/
        for (i = increment + 1;  i <= L->length ; i++) {
            if (L->r[i] < L->r[i-increment])
            {
                L->r[0] = L->r[i];  /*  �ݴ���L->r[0] */
                for (j = i-increment; j > 0 && L->r[0] < L->r[j]; j-=increment) {
                    L->r[i+increment] = L->r[j]; /*  ��¼���ƣ����Ҳ���λ�� */
                }
                L->r[j+increment] = L->r[0];
            }
        }
        printf("	��%d��������: ",++k);
        print(*L);
    }
    while(increment>1);
}




/* **************************************** */
#define N 9
int main()
{
    int i;
    int d[N]={50,10,90,30,70,40,80,60,20};
    SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
    for (i = 0; i < N; i++) {
        l0.r[i+1]=d[i];
    }
    l0.length = N;
    l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
    printf("����ǰ:\n");
    print(l0);
    printf("ð������:\n");
    BubbleSort(&l1);
    print(l1);
}