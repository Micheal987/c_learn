#include <stdio.h>
#include <stdlib.h>

int *create_array(int n)
{
    return (int *)malloc(n * sizeof(int));
}

int main()
{
    int n = 5;
    int *arr = create_array(n); // 调用指针函数
    if (arr == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    // 使用数组
    for (int i = 0; i < n; i++)
        arr[i] = i * 10;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr); // 释放内存
    return 0;
}