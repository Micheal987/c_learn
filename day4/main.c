#include <errno.h>   // 包含错误处理相关的头文件，定义了errno全局变量和perror函数
#include <stdlib.h>  // 包含标准库函数，如malloc、free等，但此代码未直接使用
#include <string.h>  // 包含字符串处理函数，如strlen、strcpy等，但此代码未直接使用
#include "tomlc17.h" // 包含tomlc17库的头文件，提供TOML解析功能

int main() // 主函数入口
{
    // 调用toml_parse_file_ex函数解析名为"config.toml"的TOML文件
    // 返回一个toml_result_t结构体，包含解析结果（成功标志、错误信息、解析出的数据表等）
    toml_result_t result = toml_parse_file_ex("config.toml");

    // 检查解析是否成功（result.ok为真表示成功）
    if (!result.ok) // 如果解析失败
    {
        perror(result.errmsg); // 使用perror打印错误信息（注意：perror通常用于输出errno对应的错误，这里直接传入了库返回的错误字符串，行为可能不符合预期，但代码如此）
    }

    // 使用toml_seek函数根据点分隔的路径"server.host"从解析出的数据表（result.toptab）中查找对应的值
    // 返回一个toml_datum_t联合体，包含值的类型（type）和具体数据（u）
    toml_datum_t name = toml_seek(result.toptab, "server.name");
    toml_datum_t host = toml_seek(result.toptab, "server.host");

    // 查找路径"server.port"对应的值
    toml_datum_t port = toml_seek(result.toptab, "server.port");

    // 打印server.name
    if (name.type != TOML_STRING) // 检查host的类型是否为字符串
    {
        perror("missing or invalid 'server.name' property in config"); // 如果不是字符串，打印错误信息
    }
    printf("server.name = %s\n", name.u.s); // 输出host的字符串值（假设类型正确）
    // 打印server.host的值
    if (host.type != TOML_STRING) // 检查host的类型是否为字符串
    {
        perror("missing or invalid 'server.host' property in config"); // 如果不是字符串，打印错误信息
    }
    printf("server.host = %s\n", host.u.s); // 输出host的字符串值（假设类型正确）

    // 打印server.port的值（期望是一个整数数组）
    if (port.type != TOML_ARRAY) // 检查port的类型是否为数组
    {
        perror("missing or invalid 'server.port' property in config"); // 如果不是数组，打印错误信息
    }
    printf("server.port = [");                // 开始打印数组的左括号
    for (int i = 0; i < port.u.arr.size; i++) // 遍历数组的每个元素
    {
        toml_datum_t elem = port.u.arr.elem[i]; // 获取当前元素的值（也是toml_datum_t类型）
        if (elem.type != TOML_INT64)            // 检查元素类型是否为64位整数
        {
            perror("server.port element not an integer"); // 如果不是整数，打印错误信息
        }
        // 打印元素值，如果i不是第一个元素，先打印逗号和空格；将int64转换为int后打印
        printf("%s%d", i ? ", " : "", (int)elem.u.int64);
    }
    printf("]\n"); // 打印数组的右括号并换行

    // 释放解析结果占用的内存（result中包含的数据表和内部结构）
    toml_free(result);

    return 0; // 程序正常结束
}