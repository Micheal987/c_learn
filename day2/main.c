#include <stdio.h>
#include <stdlib.h> // 添加 malloc 所需头文件

typedef int *int_ptr;

int_ptr new_num(int a, int b)
{
    int_ptr p = malloc(sizeof(int));
    if (p)
        *p = a + b;
    return p;
}

int main()
{
    int_ptr conf = new_num(1, 2); // 修正类型
    if (conf)                     // 检查分配是否成功
        printf("%d", *conf);      // 注意解引用
    free(conf);                   // 释放内存
    return 0;
}