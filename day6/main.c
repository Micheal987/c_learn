#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum CodeStatus
{
    OK = 200,
    FAIL = 400,
};

struct ResultData
{
    enum CodeStatus code; // 狀態碼
    char *msg;            // 訊息字串（需要動態分配或指向常數字串）
    void *data;           // 指向任意類型的資料
};

// 建立一個 ResultData 的輔助函式（動態分配訊息）
struct ResultData make_result(enum CodeStatus code, const char *msg, void *data)
{
    struct ResultData res;
    res.code = code;
    // 複製訊息字串（假設需要獨立拷貝，否則可直接指派常數字串）
    if (msg)
    {
        res.msg = malloc(strlen(msg) + 1);
        if (res.msg)
            strcpy(res.msg, msg);
    }
    else
    {
        res.msg = NULL;
    }
    res.data = data;
    return res;
}

// 釋放 ResultData 中動態分配的訊息（如果有的話）
void free_result(struct ResultData *res)
{
    if (res->msg)
    {
        free(res->msg);
        res->msg = NULL;
    }
    // data 通常由外部管理，這裡不負責釋放
}

int main()
{
    int some_value = 42;
    struct ResultData r = make_result(OK, "Success", &some_value);

    if (r.code == OK)
    {
        printf("Status: %d, Message: %s, Data: %d\n", r.code, r.msg, *(int *)r.data);
    }

    free_result(&r); // 清理動態分配的訊息
    return 0;
}