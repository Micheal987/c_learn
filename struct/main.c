#include <stdio.h>
#include <stddef.h>
struct ApiData
{
    int code;
    char msg[100];
};

struct User
{
    struct ApiData api; // 嵌套進來
    int id;
    char name[50];
};

int main()
{
    // 初始化一筆資料
    struct User my_user = {
        .api = {.code = 200, .msg = "Success"},
        .id = 1001,
        .name = "linux"};

    // 模擬：我們現在只拿到通用外殼的指標（例如在底層網路傳輸、框架回傳時）
    struct ApiData *api_ptr = &my_user.api;

    // 神奇魔法：利用著名的 container_of 巨集技術，
    // 透過計算記憶體偏移量（Offset），直接從外殼「反向回推」拿到整份 User 資料！
    struct User *user_ptr = (struct User *)((char *)api_ptr - offsetof(struct User, api));

    // 成功取出資料！
    printf("Code: %d, Msg: %s\n", api_ptr->code, api_ptr->msg);
    printf("User ID: %d, Name: %s\n", user_ptr->id, user_ptr->name);

    return 0;
}
