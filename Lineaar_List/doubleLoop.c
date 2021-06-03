

//
// Created by $Matthew on 2021-06-02.
//

#include<stdio.h>
#include<stdlib.h>

int main(){

    short a = 0100;  //八进制
    int b = -0x1;  //十六进制
    long c = 720;  //十进制

    unsigned short m = 0xffff;  //十六进制
    unsigned int n = 0x80000000;  //十六进制
    unsigned long p = 100;  //十进制

    //以无符号的形式输出有符号数
    printf("a=%#h0, b=%#x, c=%ld\n", a, b, c);
    //以有符号数的形式输出无符号类型（只能以十进制形式输出）
    printf("m=%hd, n=%d, p=%ld\n", m, n, p);


    int  row, cow;
    row = 1;
    for (row; row <= 5; ++row) {
        for (cow = 1; cow <= row; cow++) {
            printf("*");
        }
        printf("\n");
    }


    return 0;


}