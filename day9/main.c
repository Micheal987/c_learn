#include <stdio.h>
#include <stdlib.h>
int n;
int main()
{
    printf("请输入学生人数\n");
    scanf("%d", &n);
    // 分配 n 个 int 类型的内存空间
    // sizeof(int) 是每个 int 占用的字节数，乘以 n 得到总字节数
    // malloc 返回 void*，强转为 int* 以便按 int 访问
    int *scores = (int *)malloc(n * sizeof(int));
    // 检查分配是否成功：如果失败，malloc 返回 NULL
    if (scores == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    // 使用这块内存，就像使用普通数组一样
    for (int i = 0; i <= n; i++)
    {
        printf("输入第 %d 个学生的成绩:", scores[i]);
        scanf("%d", &scores[i]); // 通过下标访问
    }
    printf("\n成绩列表:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d", scores[i]);
    }
    // 释放内存，归还给系统
    free(scores);
    // 将指针设为 NULL，防止后续误用（悬空指针）
    scores = NULL;
    return 0;
}