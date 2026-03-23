#include <stdio.h>
int main()
{
    int num = 42; // 普通变量
    int *ptr;     // 声明一个指针
    ptr = &num;   // ptr存储num的地址
    printf("num 的值: %d\n", num);
    printf("num 的地址: %p\n", &num);
    printf("ptr 存储的地址: %p\n", ptr);
    printf("通过ptr访问的值: %d\n", *ptr); // *ptr就是num的值
                                           // 通过指针修改变量的值
    *ptr = 100;                            // 修改指针的值
    printf("修改后 num = %d\n", num);

    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // arr就是&arr[0]，p指向数组第一个元素

    // 通过指针访问数组元素
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d, *(p+%d) = %d\n", i, arr[i], i, *(p + i));
    }

    // 指针算术：p+1 指向下一个元素
    printf("*(p+2) = %d\n", *(p + 2)); // 输出30

    // 数组名本身不能改变指向，但指针可以移动
    p = &arr[3];
    printf("p现在指向 arr[3] = %d\n", *p);

    int x = 5, y = 10;
    printf("交换前: x=%d, y=%d\n", x, y);

    swap(&x, &y); // 传递地址
    printf("交换后: x=%d, y=%d\n", x, y);
    return 0;
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}