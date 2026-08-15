#include <stdio.h>
#include <string.h>
/*
 * union（共用體 / 聯合體） 是一種特殊的自定義數據類型。它與
 * struct（結構體）非常相似，但有一個本質上的不同：struct
 * 的所有成員各自佔用獨立的記憶體，而 union 的所有成員則共享同一塊記憶體
 */
/*
 * 共享記憶體：在任一時刻，union
 * 只能儲存其中一個成員的值。寫入新成員會覆蓋舊成員的值。大小計算：union
 * 的總大小至少等於其最大成員的大小，並且必須是其最大對齊要求（Alignment）的整數倍（可能會有末尾填充字節
 * Padding）。
 */
union MyUnionData
{
  int i;
  float f;
  char str;
};
int main()
{
  char source[] = "Hello World";

  // union 在同一時間只能初始化「一個」成員
  union MyUnionData data = {.i = 10};
  printf("初始整數值 i: %d\n", data.i);

  // 使用 strcpy 將字串複製到 union 的 str 成員中
  // 注意：這會覆蓋掉原本整數 i 的記憶體空間！
  strcpy(&data.str, source);

  // 列印複製後的字串結果
  printf("複製後的字串 str: %s\n", &data.str);

  // 4. 驗證記憶體覆蓋：此時如果去讀取
  // data.i，會讀到字串「Hell」的二進位內容，不再是 10 printf("此時的 i
  // (已被字串覆蓋): 0x%X\n", data.i);

  return 0;
}
