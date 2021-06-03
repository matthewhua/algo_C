//
// Created by Admin on 2021/6/3.
//
#include <stdio.h>

/**
 * ע�⣬�ṹ�����������������ͬ��
 * �������ڱ��ʽ�лᱻת��Ϊ����ָ�룬���ṹ����������ᣬ
 * �������κα��ʽ������ʾ�Ķ����������ϱ���
 * Ҫ��ȡ�ýṹ������ĵ�ַ��������ǰ���&�����Ը� pstu ��ֵֻ��д����
 *
 * struct stu *pstu = &stu1;
 *
 * ������д����
 *
 * struct stu *pstu = stu1;
 */
struct stu{
    char *name;  //����
    int num;  //ѧ��
    int age;  //����
    char group;  //����С��
    float score;  //�ɼ�
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
 * �ṹ��ָ����Ϊ��������
 * Ԥ������
 */
void average(struct stu *ps, int len);



/**
 * ��һ��д���У�.�����ȼ�����*��(*pointer)���ߵ����Ų����١����ȥ������д��*pointer.memberName��
 * ��ô�͵�Ч��*(pointer.memberName)�������������ȫ�����ˡ�
 * @return
 */
int main()
{
    //��ȡ�ṹ���Ա��ֵ
    printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", (*pstu).name, (*pstu).num, (*pstu).age, (*pstu).group, (*pstu).score);
    printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", pstu->name, pstu->num, pstu->age, pstu->group, pstu->score);

    //�����鳤��
    int len = sizeof(stus) / sizeof(struct stu);
    printf("Name\t\tNum\tAge\tGroup\tScore\t\n");
    printf("%d , %d, ��������Ϊ%d\n",len, sizeof(stus),sizeof(struct stu));

    for (ps = stus; ps < stus+len; ++ps) {
        printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num,ps->age, ps->group, ps->score);
    }

    average(stus, len);
}

/**
 * �ṹ���������������������ϱ�����Ϊ��������ʱ���ݵ��������ϣ�Ҳ�������г�Ա��
 * ������������һ����������ת����һ��ָ�롣����ṹ���Ա�϶࣬�����ǳ�ԱΪ����ʱ��
 * ���͵�ʱ��Ϳռ俪����ܴ�Ӱ����������Ч�ʡ�������õİ취����ʹ�ýṹ��ָ�룬��ʱ��ʵ�δ����βε�ֻ��һ����ַ���ǳ����١�
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