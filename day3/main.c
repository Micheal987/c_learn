#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int x = 1;
    int y = 2;

    printf("=== 交換前 ===\n");
    printf("x 的值: %d, 地址: %p\n", x, (void *)&x);
    printf("y 的值: %d, 地址: %p\n", y, (void *)&y);

    // 呼叫交換函數
    swap(&x, &y);

    printf("\n=== 交換後 ===\n");
    printf("x 的值: %d, 地址: %p\n", x, (void *)&x);
    printf("y 的值: %d, 地址: %p\n", y, (void *)&y);

    return 0;
}

void swap(int *a, int *b)
{
    // 這裡印出 a 和 b 指向哪裡，驗證它們是否收到了 x 和 y 的地址
    printf("\n[進入 swap 函數]\n");
    printf("指標 a 指向的地址: %p (即 x 的地址)\n", (void *)a);
    printf("指標 b 指向的地址: %p (即 y 的地址)\n", (void *)b);

    int temp = *a;
    *a = *b;
    *b = temp;
}
