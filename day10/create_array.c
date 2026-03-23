#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "create_array.h"
int *create_array(int n, int init)
{
    // 分配 n 个 int 的空间
    int *arr = (int *)malloc(n * sizeof(int));
    // 判断
    if (arr == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    // 初始化每个元素
    for (int i = 0; i < n; i++)
    {
        arr[i] = init;
    }
    return arr;
}
// 函数：打印数组
void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}