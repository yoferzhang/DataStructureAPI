// main.cpp
// 循环链表测试程序

#include <iostream>
#include <cstdio>
#include "circlelist.h"
#include "joseph.h"

const int maxn = 5;

struct Student
{
	CircleListNode circlenode;
	char name[32];
	int age;
};

void play01()
{
	Student s[maxn];
	for (int i = 0; i < maxn; ++i) {
		s[i].age = i + 1;
	}

	CircleList *list = NULL;

	list = CircleList_Create(); // 创建链表

	// 插入元素
	for (int i = 0; i < maxn; ++i) {
		// 尾插法
		int ret = CircleList_Insert(list, (CircleListNode *)&s[i], CircleList_Length(list));
		if (ret < 0) {
			printf("function CircleList_Insert err: %d\n", ret);
		}
	}

	// 遍历链表
	// 这里遍历打印两边，可以证明这是一个循环链表
	for (int i = 0; i < 2 * CircleList_Length(list); ++i) {
		Student *tmp = (Student *)CircleList_Get(list, i);
		if (tmp == NULL) {
			printf("function CircleList_Get err.\n");
		}
		printf("age: %d\n", tmp->age);
	}

	// 删除结点，通过结点位置
	while (CircleList_Length(list)) {
		Student *tmp = (Student *)CircleList_Delete(list, CircleList_Length(list) - 1);
		if (tmp == NULL) {
			printf("function CircleList_Delete err.\n");
		}
		printf("age: %d\n", tmp->age);
	}

	// 销毁链表
	CircleList_Destroy(list);

}

int main()
{
	play01(); // 为了测试数据的生命周期，所以另写一个函数调用运行
	joseph();

	return 0;
}