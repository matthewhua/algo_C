//
// Created by $Matthew on 2021-06-06.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SWAP(a, b)\
do{               \
    (a) ^= b;     \
    (b) ^= a;     \
    (a) ^= b;     \
}while(0)


struct array {
    int size;
    int used;
    int *arr;
};

void dump(struct array *array)
{
    int idx;

    for (idx = 0; idx < array->used; idx++) {
        printf("[%02d]:%08d\n", idx, array->arr[idx]);
    }
}

void alloc(struct array *array)
{
    array->arr = (int *)malloc(array->size * sizeof(int));
}

void bubble_sort(struct array *array)
{
    int i, j;

    if (array -> used <= 1)
        return;
    for ( i = 0; i < array->used; i++) {
        bool has_swap = false;
        for ( j = 0; j < array-> used - i - 1; j++) {  //单次循环
            if(array -> arr[j] > array -> arr[j+1]){
                SWAP(array->arr[j],array->arr[j+1]);
                has_swap = true;
            }
        }
        if (!has_swap)
            break;
    }
}

/**
     * 冒泡排序改进:在每一轮排序后记录最后一次元素交换的位置,作为下次比较的边界,
     * 对于边界外的元素在下次循环中无需比较.
     */
void bubble_sort2(struct array *array)
{
    int i, j;

    if (array -> used <= 1)
        return;

    // 最后一次交换的位置
    int lastExchange = 0;
    // 无序数据的边界, 每次只需要比较到这里退出即可
    int sortBorder = array->used -1;
    for (i = 0; i < array->used; i++) {
        bool has_swap = false;
        for ( j = 0; j < sortBorder; j++) {  //单次循环
            if(array -> arr[j] > array -> arr[j+1]){
                int temp;
                temp = array->arr[j];
                array->arr[j] = array->arr[j+1];
                array->arr[j+1] = temp;
                // 此次冒泡有数据交换
                has_swap = true;
                // 更新最后一次交换的位置
                lastExchange = j;
            }
        }
        sortBorder = lastExchange;
        if (!has_swap) // 没有数据交换，提前退出
            break;
    }
}


void insertSort(struct array *array)
{
    int i, j;
    if (array->used <= 1) return;

    for (i = 1; i < array->used; i++) {
        int sentinel = array->arr[i];

        for (j = i - 1; j >= 0; j--) {
            if (sentinel < array->arr[j])
                array->arr[j+1] = array->arr[j];
            else
                break;
        }
        array->arr[j+1] = sentinel;
    }
}



/**
 * 希尔排序的插入
 */
void ShellInsert()
{
    int i, j;


}


void ShellSort(struct array *array)
{
    // 按增量序列 d[0..t-1] 对顺序表 R 作希尔排序
    int k;

}


void select_sort(int a[], int size)
{

}


void bubble_sort_test()
{
    int idx;
    struct array ten_int = {10, 0, NULL};

    alloc(&ten_int);
    for (idx = 0; idx < 10; idx++) {
        ten_int.arr[idx] = 30 - idx;
    }
    ten_int.used = 10;
    dump(&ten_int);
    bubble_sort(&ten_int); //普通 冒泡排序
    //bubble_sort2(&ten_int); //优化后排序
    dump(&ten_int);
}


void insertion_sort_test()
{
    int idx;
    struct array ten_int = {10, 0, NULL};

    alloc(&ten_int);
    for (idx = 0; idx < 10; idx++)
        ten_int.arr[idx] = 30 - idx;
    ten_int.used = 10;
    dump(&ten_int);
    insertSort(&ten_int);
    dump(&ten_int);
}




int main()
{
    bubble_sort_test();
    //insertion_sort_test();
    return 0;
}