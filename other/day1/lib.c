#include <stdio.h>
#include "core.h"
void run()
{
    int conf = config();
    printf("程序开始运行...\n");
    printf("this is lib:%d\n", conf);
}
void println()
{
    printf("hello word! \n");
}