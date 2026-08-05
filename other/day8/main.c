#include <stdio.h>  // 包含标准输入输出库，用于 printf 和 scanf
#include <stdlib.h> // 包含标准库，提供 malloc、realloc、free 等内存管理函数

/*
1 2 3 4 5
bf_arr=0x2d4ad010
arr=0x2d4ad010
size=0
bf_arr=0x2d4ad010
arr=0x2d4ad010
size=1
bf_arr=0x2d4ad010
arr=0x2d4ad010
size=2
bf_arr=0x2d4ad010
arr=0x2d4ad010
size=3
bf_arr=0x2d4ad010
realloc_arr=0x2d4ad850
arr=0x2d4ad850
size=4
*/
int main()
{
    int capacity = 4;                                 // 初始数组容量（最多可存储的元素个数）
    int size = 0;                                     // 当前数组中实际存储的元素个数
    int *arr = (int *)malloc(capacity * sizeof(int)); // 动态分配初始容量为 4 的 int 数组 //sizeof(int) 计算int类型在内存中所占的字节（取决你的机器上32还是64）
    int num;                                          // 用于临时存储从输入读取的整数

    // 循环读取整数，scanf 成功读取一个整数时返回 1，否则退出循环（遇到非数字或 EOF）
    while (scanf("%d", &num) == 1)
    {
        // 如果当前元素个数已达到容量上限，则需要扩容
        printf("bf_arr=%p\n", arr);
        if (size == capacity)
        {
            capacity *= 2; // 将容量扩大为原来的两倍
            // 使用 realloc 重新分配内存，保留原有数据，新容量为 capacity
            arr = (int *)realloc(arr, capacity * sizeof(int)); // sizeof(int) 计算int类型在内存中所占的字节（取决你的机器上32还是64）
            printf("realloc_arr=%p\n", arr);
        }
        // 将新读取的数字存入数组，并增加 size
        printf("arr=%p\n", arr);
        printf("size=%d\n", size);
        arr[size++] = num;
    }

    // 使用数组：遍历并打印所有已存储的整数
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); // 输出每个元素，空格分隔
    }

    free(arr); // 释放动态分配的内存，防止内存泄漏
    return 0;  // 程序正常结束
}