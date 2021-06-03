//
// Created by Admin on 2021/6/3.
//


// 普通宏定义
#include <stdio.h>
#define Mon 1
#define Tues 2
#define Wed 3
#define Thurs 4
#define Fri 5
#define Sat 6
#define Sun 7


void test_length();

int main()
{
    /**
     * enum week{ Mon = 1, Tues = 2, Wed = 3, Thurs = 4, Fri = 5, Sat = 6, Sun = 7 };
     * 这样枚举值就从 1 开始递增，跟上面的写法是等效的。
     */
    enum week{ Mon1 = 1, Tues1, Wed1, Thurs1, Fri1, Sat1, Sun1 } day2;
    int day;
    scanf_s("%d", &day);
    switch (day) {
        case Mon: puts("Monday"); break;
        case Tues: puts("Tuesday"); break;
        case Wed: puts("Wednesday"); break;
        case Thurs: puts("Thursday"); break;
        case Fri: puts("Friday"); break;
        case Sat: puts("Saturday"); break;
        case Sun: puts("Sunday"); break;
        default: puts("Error!");
    }
    return 0;
}