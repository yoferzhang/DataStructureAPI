// main.cpp
// 队列类测试程序

#include <iostream>
#include <cstdio>
#include "linkqueue.hpp"

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

	LinkQueue<Student> lq; // 创建队列
	lq.append(s1); // 入队列
	lq.append(s2);
	lq.append(s3);

	Student tmp;
	lq.header(tmp);
	cout << "header of queue: " << tmp.age << endl;
	cout << "length of queue: " << lq.length() << endl;

	while (lq.length() > 0) {
		lq.retieve(tmp);
		cout << tmp.age << " ";
	}
	cout << endl;

	lq.clear();

}

int main()
{
	play();

	return 0;
}
