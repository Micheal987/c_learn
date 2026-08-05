#include <stdio.h>
#include <string.h>

union SensorData
{
    int temperature;
    float humidity;
    char code[4];
};

int main()
{
    union SensorData data;

    // 使用整數
    data.temperature = 25;
    printf("Temperature: %d\n", data.temperature);

    // 改用浮點數（覆蓋之前的整數）
    data.humidity = 65.5f;
    printf("Humidity: %.1f\n", data.humidity);
    // 此時 data.temperature 的值已被破壞

    // 使用字串（小心長度）
    strcpy(data.code, "AB");
    printf("Code: %s\n", data.code);

    // 檢查 union 大小
    printf("Size of union: %zu\n", sizeof(data));

    return 0;
}