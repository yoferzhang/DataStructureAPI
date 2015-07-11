// main.cpp

#include <iostream>
#include <cstdio>
#include "linklist.h"

using namespace std;

typedef struct _Student
{
	LinkListNode node;
	char	name[32];
	int		age;
}Student;

int main()
{
	Student s1, s2, s3, s4, s5, s6;
	s1.age = 21;
	s2.age = 22;
	s3.age = 23;
	s4.age = 24;
	s5.age = 25;
	s6.age = 26;

	// 创建链表
	Student *list = (Student *)LinkList_Create();

	// 插入结点
	LinkList_Insert(list, (LinkListNode *)&s1, 0);
	LinkList_Insert(list, (LinkListNode *)&s2, 0);
	LinkList_Insert(list, (LinkListNode *)&s3, 0);
	LinkList_Insert(list, (LinkListNode *)&s4, 0);
	LinkList_Insert(list, (LinkListNode *)&s5, 0);
	LinkList_Insert(list, (LinkListNode *)&s6, 3);

	// 遍历链表
	for (int i = 0; i < LinkList_Length(list); ++i) {
		Student *tmp = (Student *)LinkList_Get(list, i);
		if (tmp == NULL) {
			return 0;
		}
		printf("age: %d\n", tmp->age);
	}

	// 删除链表结点
	while (LinkList_Length(list)) {
		Student *tmp = (Student *)LinkList_Delete(list, 0);
		if (tmp == NULL) {
			return 0;
		}
		printf("age: %d\n", tmp->age);
	}

	LinkList_Destroy(list);

	return 0;
}