//
// Created by $Matthew on 2021-06-06.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct array {
    int size;
    int used;
    int *arr;
};

void dump(struct array *array)
{
    int idx;

    for (int idx = 0; idx < array->used; ++idx) {
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
    for ( i = 0; i < array->used; ++i) {
        bool has_swap = false;
        for ( j = 0; j < array-> used; ++j) {
            if(array -> arr[j] > array -> arr[j + 1]){
                int temp;
                temp = array->arr[i];
                array->arr[j] = array->arr[j + 1];
                array->arr[j+1] = temp;
                has_swap = true;
            }
        }
        if (!has_swap)
            break;
    }
}