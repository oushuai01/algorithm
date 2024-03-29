/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-07-04 21:07:23
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-13 20:39:12
 * @FilePath: \algorithm\LiKou\debug\debug.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <cstring>
union TypeConverter {
    float f;
    unsigned int ui;
};


union BigSmall {
    int val;
    char byte_[sizeof(int)];
};

void fun(int x, int y, int z)
{
    std::cout << x << &x << std::endl;
    std::cout << y << &y << std::endl;
    std::cout << z << &z << std::endl;
}

int main() {
        //fun(1, 2, 3);
        //int a = 2;
    //printf("%d, %d, %d", a, (a = (a + 2)), (a = (a + 3)));
    int a = 65;
    char b = 67;
    int *pa = &a;
    char* pb = &b;
    int brr[2] = {1,2};
    std::cout << &brr + 1 << " " << brr + 1 << " " << &brr[0] << std::endl;   //&brr + 1 偏移整个数组长度
    std::cout << pa << " " << pa + 1 << std::endl;
    std::cout << (int*)pb << " " <<  (int*)(pb + 1) << std::endl;
    std::cout << pb << " " <<  (pb + 1) << std::endl;

    std::cout << sizeof(int*) << "  " << sizeof(char*) << std::endl;
    TypeConverter converter;
    BigSmall bs;
    bs.val = 1;
    char str[20] = "123456789";
    int vale = 4;
    int arr[10];
    
    memset(arr, (char)1, sizeof(arr));
    for(int num : arr)
    std::cout << std::hex << num << " ";
    std::cout << std::endl;
    std::cout << (char*)(&vale + 1) - (char*)(&vale) << std::endl;
    std::cout << sizeof(str)  << "  " << strlen(str) << std::endl;
    std::cout << "bs.byte[0]: " << (int)bs.byte_[0] << "#" << std::endl;

    // 将浮点数赋值给联合体的浮点数成员
    converter.f = 3.14f;

    // 通过联合体的整数成员访问内存中的字节表示
    std::cout << "Float: " << converter.f << std::endl;
    std::cout << "Integer: " << converter.ui << std::endl;

    // 将整数赋值给联合体的整数成员
    converter.ui = 12345678;

    // 通过联合体的浮点数成员访问内存中的字节表示
    std::cout << "Integer: " << converter.ui << std::endl;
    std::cout << "Float: " << converter.f << std::endl;

    return 0;
}