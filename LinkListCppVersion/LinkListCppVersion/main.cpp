#include <iostream>
#include <cstdio>
#include "linklist.h"

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

	LinkList<Student> list; // 创建链表

	// 插入元素
	list.insert(s1, 0);
	list.insert(s2, 0);
	list.insert(s3, 0);

	// 遍历元素
	Student tmp;
	for (int i = 0; i < list.getLen(); ++i) {
		list.get(i, tmp);
		cout << "age: " << tmp.age << endl;
	}

	// 删除元素
	while (list.getLen()) {
		list.del(0, tmp);
		cout << "age: " << tmp.age << endl;
	}

}

int main()
{
	play();

	return 0;
}