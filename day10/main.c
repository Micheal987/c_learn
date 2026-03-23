#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "create_array.h"
#include "create_students.h"
int main()
{
    // 动态struct
    int n = 100000; // 10 万条学生记录（大数据）
    // 创建动态结构体数组（堆上分配）
    Student *students = create_students(n);
    // 动态数组
    int *scores = create_array(5, 100); // 初始化元素为：5个10
    if (scores == NULL || students == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    /*
    student 初始化数据
    */
    init_students(students, n);

    /*
    动态数组的打印
    */
    // 打印
    printf("数组内容: ");
    print_array(scores, 5);
    /*
    学生打印
    */
    // 长生命周期：students 指针在 main 函数中一直有效，直到 free
    printf("前 5 条学生记录:\n");
    print_students(students, n, 5);
    // 释放内存
    free(scores);
    free(students);
    students = NULL;
    scores = NULL;
    return 0;
}
