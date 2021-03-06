//
// Created by Admin on 2021/6/3.
//
#include <stdio.h>

/**
 * 注意，结构体变量名和数组名不同，
 * 数组名在表达式中会被转换为数组指针，而结构体变量名不会，
 * 无论在任何表达式中它表示的都是整个集合本身，
 * 要想取得结构体变量的地址，必须在前面加&，所以给 pstu 赋值只能写作：
 *
 * struct stu *pstu = &stu1;
 *
 * 而不能写作：
 *
 * struct stu *pstu = stu1;
 */
struct stu{
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在小组
    float score;  //成绩
} stu1 = { "Tom", 12, 18, 'A', 136.5 },
*pstu = &stu1,
stus[] = {
{"Zhou ping", 5, 18, 'C', 145.0},
{"Zhang ping", 4, 19, 'A', 130.5},
{"Liu fang", 1, 18, 'A', 148.5},
{"Cheng ling", 2, 17, 'F', 139.0},
{"Wang ming", 3, 17, 'B', 144.5}
}, *ps;

/**
 * 结构体指针作为函数参数
 * 预先申明
 */
void average(struct stu *ps, int len);



/**
 * 第一种写法中，.的优先级高于*，(*pointer)两边的括号不能少。如果去掉括号写作*pointer.memberName，
 * 那么就等效于*(pointer.memberName)，这样意义就完全不对了。
 * @return
 */
int main()
{
    //读取结构体成员的值
    printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", (*pstu).name, (*pstu).num, (*pstu).age, (*pstu).group, (*pstu).score);
    printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", pstu->name, pstu->num, pstu->age, pstu->group, pstu->score);

    //求数组长度
    int len = sizeof(stus) / sizeof(struct stu);
    printf("Name\t\tNum\tAge\tGroup\tScore\t\n");
    printf("%d , %d, 单个长度为%d\n",len, sizeof(stus),sizeof(struct stu));

    for (ps = stus; ps < stus+len; ++ps) {
        printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num,ps->age, ps->group, ps->score);
    }

    average(stus, len);
}

/**
 * 结构体变量名代表的是整个集合本身，作为函数参数时传递的整个集合，也就是所有成员，
 * 而不是像数组一样被编译器转换成一个指针。如果结构体成员较多，尤其是成员为数组时，
 * 传送的时间和空间开销会很大，影响程序的运行效率。所以最好的办法就是使用结构体指针，这时由实参传向形参的只是一个地址，非常快速。
 * @param ps
 * @param len
 */
void average(struct stu *ps, int len){
    int i, num_140 = 0;
    float average, sum = 0;
    for (i = 0; i < len; ++i) {
        sum += (ps + i) -> score;
        if ((ps + i)->score < 140) num_140++;
    }
    average = sum/5;
    printf("sum=%.2f\naverage=%.2f\nnum_140=%d\n", sum, average, num_140);
}