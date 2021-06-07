//
// Created by Matthew on 2021/6/7.
// 玩转数据结构
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

#define MAX_LENGTH_INSERT_SORT 7 /* 用于快速排序时判断是否选用插入排序阙值 */

typedef int Status; //可以自定义使用
#define MAXSIZE 10000  /* 用于要排序数组个数最大值，可根据需要修改 */

#define SWAP(a,b) \
do{\
	(a) ^= (b);\
	(b) ^= (a);\
	(a) ^= (b);\
}while(0)

typedef struct {
    int r[MAXSIZE+1]; /* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
    int length;         /* 用于记录顺序表的长度 */
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


// 倒序排列
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


/* 对顺序表L作简单选择排序 */
void select_sort(SqList *L)
{
    int i,j,min;
    for (i = 1; i < L->length; i++) {
        min = i;
        for (j = i+1; j <L->length ; ++j) { /* 循环之后的数据 */
            if (L->r[min] > L->r[j]) /* 如果有小于当前最小值的关键字 */
                min = j;            /* 将此关键字的下标赋值给min */
        }
        if (i != min)
            SWAP(i, min);
    }
}

/**
 *  对顺序表L作希尔排序
 * @param L
 */
void shell_sort(SqList *L)
{
    int i, j, k = 0;
    int increment = L->length;
    do {
        increment = increment/3 + 1; /* 增量序列*/
        for (i = increment + 1;  i <= L->length ; i++) {
            if (L->r[i] < L->r[i-increment])
            {
                L->r[0] = L->r[i];  /*  暂存在L->r[0] */
                for (j = i-increment; j > 0 && L->r[0] < L->r[j]; j-=increment) {
                    L->r[i+increment] = L->r[j]; /*  记录后移，查找插入位置 */
                }
                L->r[j+increment] = L->r[0];
            }
        }
        printf("	第%d趟排序结果: ",++k);
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
    printf("排序前:\n");
    print(l0);
    printf("冒泡排序:\n");
    BubbleSort(&l1);
    print(l1);
}