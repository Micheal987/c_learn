#ifndef CREATE_ARRAY_H
#define CREATE_ARRAY_H
// 函数：创建动态数组并初始化为指定值
// 参数 n: 元素个数
// 参数 init: 每个元素的初始值
// 返回值: 指向数组的指针，失败返回 NULL
int *create_array(int n, int init);
// 函数：打印数组
void print_array(int *arr, int n);
#endif