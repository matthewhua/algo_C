//
// Created by $Matthew on 2021-06-06.
//

#include <stdio.h>

#define MAXSIZE 100
typedef int KeyType;
typedef struct s{
    KeyType key;
} RecType;

typedef RecType SeqList[MAXSIZE+1];
SeqList R;


//自定义的输出函数
void print(SeqList R, int n)
{
    // 对顺序表R 做直接插入排序
    int i, j;
    for (i= 2; i < n; ++i) {
        if (R[i].key < R[i - 1].key){
            R[0] = R[i];
            for ( j = i - 1 ; R[0].key < R[j].key ; j--)
                R[j + 1] = R[j];
            R[j + 1] = R[0];
        }
    }
}

int main()
{
     SeqList list[] = {1 ,3 ,4,5,2, 8, 6, 5};
     print(list, 8);
     printf("长度为%d\n", sizeof(list)/sizeof(struct s));
     for (int i = 0; i < 8; ++i) {
        printf("%d\n", list[i]);
    }
}