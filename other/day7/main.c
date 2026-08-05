#include <stdio.h>
#include <stdbool.h>

bool max(int a, int b); // 函数的原型声明
int sum(int a, int b);  // 函数的原型声明
int main()
{
    if (max(11, 10))
    {
        printf("sum val is=%d", sum(1, 2));
    }
    else
        printf("default");
    return 0;
}

bool max(int a, int b)
{
    return a > b;
}
int sum(int a, int b)
{
    return a + b;
}