//
// Created by Admin on 2021/6/3.
//

#include <stdio.h>

struct {
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group; // 所在小组
    float  score; // 成绩
}class[] = {
        {"Li ping", 5, 18, 'C', 145.0},
        {"Zhang ping", 4, 19, 'A', 130.5},
        {"He fang", 1, 18, 'A', 148.5},
        {"Cheng ling", 2, 17, 'F', 139.0},
        {"Wang ming", 3, 17, 'B', 144.5},
        {"Matthew", 3, 18, 'A', 150}
};

int main()
{
    int i, num_140 = 0;
    float sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += class[i].score;
        if (class[i].score < 140) num_140++;
    }

    printf("sum=%.2f\naverage=%.2f\nnum_140=%d\n", sum, sum/5, num_140);
}