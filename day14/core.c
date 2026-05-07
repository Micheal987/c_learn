#include "core.h"
#include <stdio.h>

String run(const String *s) {
    if (s == NULL || s->data == NULL) {
        return (String){NULL, 0};
    }

    // 假設你在裡面修改了字串（這只是範例）
    // 重新計算長度確保準確
    String result;
    result.data = s->data;
    result.length = strlen(s->data); 

    printf("Processing: %s (Auto-length: %zu)\n", result.data, result.length);
    
    return result;
}
