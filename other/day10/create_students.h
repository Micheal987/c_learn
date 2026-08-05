#ifndef CREATE_STUDENTS_H
#define CREATE_STUDENTS_H
// 创建动态结构体数组
// n: 学生数量（动态大小）
// 返回值：指向 Student 数组的指针，失败返回 NULL
typedef struct
{
    int id;
    char name[50];
    float score;
} Student;
Student *create_students(int n);
// 初始化结构体数组（模拟从数据源填充）
void init_students(Student *students, int n);
// 打印部分学生信息
void print_students(Student *students, int n, int limit);
#endif