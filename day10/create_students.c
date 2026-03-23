#include <stdio.h>
#include <stdlib.h>
#include "create_students.h"
Student *create_students(int n)
{
    Student *students = (Student *)malloc(n * sizeof(Student)); // 一次性分配 n 个 Student 结构体的连续空间
    if (students == NULL)
        return NULL;
    return students;
}
void init_students(Student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        students[i].id = i + 1;
        // 生成简单名字，实际可从外部传入
        sprintf(students[i].name, "Student_%d", i + 1);
        students[i].score = 60.0 + (i % 41); // 60~100 之间的分数
    }
}
void print_students(Student *students, int n, int limit)
{
    int count = (n < limit) ? n : limit;
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d, Name: %s, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
    if (n > limit)
        printf("... 共 %d 条记录\n", n);
}