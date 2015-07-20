// main.cpp
// 链式存储栈类的测试程序

#include <iostream>
#include <cstdio>
#include "linkstack.hpp"

using namespace std;

struct Student
{
	char name[32];
	int age;
};

void play()
{
	Student s1, s2, s3;
	s1.age = 21;
	s2.age = 22;
	s3.age = 23;

	LinkStack<Student> ls; // 创建栈

	// 入栈
	ls.push(s1);
	ls.push(s2);
	ls.push(s3);

	// 获取栈顶元素
	Student tmp;
	ls.top(tmp);
	cout << "top of stack: " << tmp.age << endl;
	cout << "size of stack: " << ls.size() << endl;

	// 出栈
	while (ls.size() > 0) {
		ls.pop(tmp);
	}

	ls.clear();

}

int main()
{
	play();

	return 0;
}