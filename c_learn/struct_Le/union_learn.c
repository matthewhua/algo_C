//
// Created by Admin on 2021/6/3.
//

//结构体和共用体的区别在于：结构体的各个成员会占用不同的内存，互相之间没有影响；而共用体的所有成员占用同一段内存，修改一个成员会影响其余所有成员

union data
{
    /* data */
    int n;
    char ch;
    double f;
} a, b, c;
