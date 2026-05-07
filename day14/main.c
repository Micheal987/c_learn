#include "core.h"
#include <stdio.h>

int main() {
    // 使用宏自動初始化
    String input = STRING("Hello Word");

    printf("Data: %s, Length: %zu\n", input.data, input.length);

    String output = run(&input);

    return 0;
}
