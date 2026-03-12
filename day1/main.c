#include <stdio.h>
#include "lib.h"
enum StatCode
{
    OK,
    Success,
};
int main()
{
    run();
    printf("enums:---%d", Success);
    return 0;
}