//
// Created by $Matthew on 2021-06-02.
//

/* 线性表的顺序存储实现 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义符号常量
#define List_INIT_SIZE 50 /* 线性表存储空间的初始分配量 */
#define LISTINCREMENT 10 /* 线性表存储空间的分配增量 */
#define OK 1
#define ERROR 0
#define OVERFLOW -2

// 定义元素类型
typedef int ElemType;

// 定义顺序表类型
typedef struct {
    ElemType  *elem; // 元素
    int length;     /* 当前长度 */
    int listsize;   /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
} SqlLIst;   /* 顺序表类型 */


//  初始化——构造空顺序表  //malloc
int InitList(SqlLIst *L){
    // 获取顺序表基址
    L->elem = (ElemType *) malloc(sizeof(ElemType));
    // 存储空间分配失败
    if (!L->elem) return ERROR;
    // 空表长度为0
    L->length = 0;
    // 分配给空表的存储容量
    L->listsize = List_INIT_SIZE;
    return OK;
}


// 查找——获取顺序表第i个元素
ElemType GetListElem(SqlLIst *L, int i){
    // 检查i的合法性
    if (i < 1 || i > L -> length)
        return ERROR;
    else
        return L->elem[i - 1];
}

int ListLength(SqlLIst L)
{
    return L.length;
}

