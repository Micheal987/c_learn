#include "stdio.h"

int main() {
  // 字符类型指的是单个字符，类型声明使用char关键字。
  char c = 'B'; // or   char c = 66;
  // 整数类型用来表示较大的整数，类型声明使用int关键字。
  int age = 20;
  /*
   signed，unsigned
   C
   语言使用signed关键字，表示一个类型带有正负号，包含负值；使用unsigned关键字，表示该类型不带有正负号，只能表示零和正整数。

   对于int类型，默认是带有正负号的，也就是说int等同于signed
   int。由于这是默认情况，关键字signed一般都省略不写，但是写了也不算错。
   */
  signed int year; // or int year
  // int类型也可以不带正负号，只表示非负整数。这时就必须使用关键字unsigned声明变量。
  unsigned int a;
  /*
   * 整数变量声明为unsigned的好处是，同样长度的内存能够表示的最大整数值，增大了一倍。比如，16位的signed int最大值为32,767，而unsigned int的最大值增大到了65,535。

   unsigned int里面的int可以省略，所以上面的变量声明也可以写成下面这样。
   */
  unsigned a1;
  // 字符类型char也可以设置signed和unsigned。
  signed char c1;   // 范围为 -128 到 127
  unsigned char c2; // 范围为 0 到 255
  printf("hello word");
  return 0;
}
