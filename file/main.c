#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("config.toml", "r");
    if (!fp)
        return 1;
    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
    return 0;
}