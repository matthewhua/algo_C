//
// Created by Admin on 2021/6/3.
//

#include <stdio.h>

int main()
{
    int a= 0, b = 0, c = 0, d =0 ;
    printf("请输入数据 a:");
    scanf("%d", &a); //输入整数并赋值给变量a
    printf("请输入数据 b:");
    scanf("%d", &b); //输入整数并赋值给变量b
    printf("a+b=%d\n", a+b);  //计算a+b的值并输出
    scanf("%d %d", &c, &d);
    printf("c*d=%d\n", c*d);  //计算c*d的值并输出

    return 0;
}