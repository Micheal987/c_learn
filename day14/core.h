#pragma once

#include <stddef.h>
#include <string.h> // 為了使用 strlen

typedef struct {
    char* data;
    size_t length;
} String;

// 優化：自動計算長度的宏
// #s 會把參數變成字串，strlen 會在編譯階段或運行初期算出長度
#define STRING(s) { (char*)(s), strlen(s) }

String run(const String *s);
