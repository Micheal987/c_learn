#include <stdio.h>  // 标准输入输出库，用于printf和scanf
#include <string.h> // 字符串处理库，用于strlen
#include "uthash.h" // uthash哈希表库，提供哈希表操作宏

// 枚举类型，表示星期几，每个枚举值对应一个整数（默认从0开始）
enum Week
{
    MON, // 星期一，值为0
    TUE, // 星期二，值为1
    WED, // 星期三，值为2
    THU, // 星期四，值为3
    FRI, // 星期五，值为4
    SAT, // 星期六，值为5
    SUN  // 星期日，值为6
};

// 哈希表条目结构体
struct Map
{
    const char *str;   // 字符串键，例如"MON"
    enum Week code;    // 对应的枚举值
    UT_hash_handle hh; // uthash内部使用的哈希句柄，必须包含在结构体中
};

struct Map *map = NULL; // 定义全局哈希表指针，初始为NULL，表示空表

// 向哈希表中添加一个映射条目的函数
void add_mapping(const char *str, enum Week code)
{
    // 动态分配一个新的Map结构体，用于存储该映射
    struct Map *entry = malloc(sizeof(struct Map));
    entry->str = str;   // 设置字符串键（注意：这里直接使用传入的指针，需确保字符串生命周期）
    entry->code = code; // 设置对应的枚举值
    // 使用uthash的HASH_ADD_KEYPTR宏将条目加入哈希表
    // 参数：hh字段名，哈希表头指针，键指针，键长度，待添加的条目指针
    HASH_ADD_KEYPTR(hh, map, entry->str, strlen(entry->str), entry);
}

// 根据字符串在哈希表中查找对应的枚举值
enum Week lookup(const char *str)
{
    struct Map *entry; // 用于接收找到的条目指针
    // 使用uthash的HASH_FIND_STR宏在哈希表中查找字符串
    // 参数：哈希表头指针，要查找的字符串，接收结果的指针
    HASH_FIND_STR(map, str, entry);
    // 如果找到条目，返回其code；否则返回-1（-1不是有效的枚举值，表示未找到）
    return entry ? entry->code : -1;
}

int main()
{
    //
    int num;
    printf("输入一个整数: ");
    if (scanf("%d", &num) == 1)
    { // 检查输入是否成功
        if (num % 2 == 0)
        { // 正确的奇偶判断
            printf("偶数\n");
        }
        else
        {
            printf("奇数\n");
        }
    }
    else
    {
        printf("输入无效\n");
    };
    // 向哈希表中添加所有星期缩写到枚举值的映射
    add_mapping("MON", MON); // 添加"MON" -> MON
    add_mapping("TUE", TUE); // 添加"TUE" -> TUE
    // ... 添加所有映射（此处省略了WED到SUN的添加，实际应全部添加）

    char input[20];     // 定义一个字符数组，用于存储用户输入的字符串
    printf("输入星期"); // 提示用户输入
    scanf("%s", input); // 读取用户输入的字符串（注意：input已是数组首地址，无需&）

    enum Week code = lookup(input); // 在哈希表中查找输入字符串对应的枚举值
    if (code != -1)                 // 如果找到了（即返回的不是-1）
    {
        switch (code) // 根据枚举值进行分支处理
        {
        case MON:
            printf("今天是星期一\n");
            break;
        case THU:
            printf("今天是星期二\n");
            break;
        case WED:
            printf("今天是星期三\n");
            break;
        case TUE:
            printf("今天是星期四\n");
            break;
        case FRI:
            printf("今天是星期五\n");
            break;
        case SAT:
            printf("今天是星期六\n");
            break;
        case SUN:
            printf("今天是星期日\n");
            break;
            // 不可能
        default:
            printf("输入错误\n");
            break;
        }
    }
    return 0; // 程序正常结束
}