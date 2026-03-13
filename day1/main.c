#include <stdio.h>
#include <stdbool.h> // C99标准，提供布尔类型
#include "lib.h"

// 函数声明
int add(int a, int b);
void new();
void new_enum();
void new_data();
void funcA();
void printMessage();

// 枚举类型定义：Weekday
enum Weekday
{
    MON, // 0
    TUE, // 1
    WED, // 2
    THU, // 3
    FRI, // 4
    SAT, // 5
    SUN  // 6
};

// 枚举类型定义：Color，指定初始值
enum Color
{
    RED = 5,
    GREEN = 10,
    BLUE = 15
};

// 结构体类型定义：Person
struct Person
{
    char name[50];
    int age;
    float height;
}; // 注意：这里去掉Person变量，保留类型定义

// 共用体类型定义：Data
union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    run();     // 调用run函数，打印开始信息
    println(); // 打印空行

    /* 指针类型演示 */
    int *ptr;         // 声明一个指向int的指针
    char *strPtr;     // 声明一个指向char的指针
    void *genericPtr; // 声明一个通用指针（可以指向任何类型）
    int **ptrToPtr;   // 声明一个指向指针的指针

    int value = 42;          // 定义一个int变量
    ptr = &value;            // 让ptr指向value
    strPtr = "Hello, world"; // 让strPtr指向字符串常量
    genericPtr = &value;     // 通用指针指向value
    ptrToPtr = &ptr;         // 指针的指针指向ptr

    // 打印指针的值和它们指向的值
    printf("ptr 指向的地址: %p, 该地址存储的值: %d\n", (void *)ptr, *ptr);
    printf("strPtr 指向的字符串: %s\n", strPtr);
    printf("genericPtr 指向的地址: %p\n", genericPtr);
    printf("ptrToPtr 指向的地址: %p, 该地址存储的指针指向的值: %d\n",
           (void *)ptrToPtr, **(ptrToPtr));

    // 枚举类型使用
    enum Weekday today = WED;   // today赋值为WED（值为2）
    enum Color myColor = GREEN; // myColor赋值为GREEN（值为10）
    printf("today (WED) = %d\n", today);
    printf("myColor (GREEN) = %d\n", myColor);

    // 调用其他演示函数
    new();
    new_enum();
    new_data();
    funcA();
    printMessage();

    return 0;
}

// 函数定义：add，返回两数之和
int add(int a, int b)
{
    return a + b;
}

// new函数：演示基础类型、数组和指针
void new()
{
    printf("\n--- new() 函数演示 ---\n");

    /*
    基础类型
    */
    int age = 0;       // 定义并初始化int类型变量
    float price = 1.2; // 定义并初始化float类型变量
    // 修复：char grade = "man"; 错误，应使用字符数组或指针
    char *grade = "man"; // 定义指向字符串的指针
    bool flag = true;    // 定义布尔类型变量

    printf("age = %d\n", age);
    printf("price = %.2f\n", price);
    printf("grade = %s\n", grade);
    printf("flag = %d\n", flag); // true在C中通常为1

    /*
    数组
    */
    int arr[2] = {1, 2};  // 包含2个int的数组
    char str[] = "Hello"; // 字符数组（字符串）
    int matrix[3][4];     // 3行4列的二维数组，未初始化

    printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
    printf("str = %s\n", str);
    // 打印二维数组首元素地址作为示例
    printf("matrix 的首地址: %p\n", (void *)matrix);

    /*
    指针
    */
    int *ptr;         // 指向int的指针
    char *strPtr;     // 指向char的指针
    void *genericPtr; // 通用指针
    int **ptrToPtr;   // 指向指针的指针

    int num = 100;
    ptr = &num;                // ptr指向num
    strPtr = "pointer string"; // strPtr指向字符串常量
    genericPtr = &num;         // 通用指针指向num
    ptrToPtr = &ptr;           // ptrToPtr指向ptr

    printf("*ptr = %d\n", *ptr);
    printf("strPtr指向的字符串: %s\n", strPtr);
    printf("genericPtr指向的值: %d\n", *(int *)genericPtr); // 需强制转换
    printf("**ptrToPtr = %d\n", **ptrToPtr);
}

// new_enum函数：演示枚举类型
void new_enum()
{
    printf("\n--- new_enum() 函数演示 ---\n");
    enum Weekday today = WED;                  // 使用枚举常量
    enum Color myColor = GREEN;                // 使用枚举常量
    printf("today (WED) = %d\n", today);       // 输出2
    printf("myColor (GREEN) = %d\n", myColor); // 输出10
}

// new_data函数：演示共用体类型
void new_data()
{
    printf("\n--- new_data() 函数演示 ---\n");
    union Data data; // 定义共用体变量
    data.i = 10;     // 使用int成员
    printf("data.i = %d\n", data.i);
    data.f = 1.1; // 使用float成员，覆盖int成员
    printf("data.f = %.2f\n", data.f);
    // 注意：此时data.i的值已被覆盖，为未定义
    printf("data.i 现在变成了: %d (可能无意义)\n", data.i);
}

// funcA函数：演示函数指针
void funcA()
{
    printf("\n--- funcA() 函数演示 ---\n");
    int add(int a, int b);    // 函数声明（冗余，已有全局声明）
    int (*funcPtr)(int, int); // 声明一个函数指针，指向返回int、接受两个int参数的函数
    funcPtr = &add;           // 让funcPtr指向add函数

    int result = funcPtr(3, 5); // 通过函数指针调用函数
    printf("通过函数指针调用add(3,5)得到: %d\n", result);
}

// printMessage函数：简单的打印函数
void printMessage(void)
{
    printf("\n--- printMessage() 函数 ---\n");
    printf("你好\n");
}