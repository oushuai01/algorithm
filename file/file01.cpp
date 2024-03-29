#include <iostream>
#include "string.h"
#include <fstream>
using namespace std;

//   写文件步骤如下：
// 1. 包含头文件   
//    \#include <fstream\>

// 2. 创建流对象  
//    ofstream ofs;

// 3. 打开文件
//    ofs.open("文件路径",打开方式);

// 4. 写数据
//    ofs << "写入的数据";

// 5. 关闭文件
//    ofs.close();

void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);

	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	ofs.close();
}

int main() {

	test01();
	//system("pause");

	return 0;
}

//后续的文件操作以后再看
//  ..............