// main.cpp
#include <iostream>
#include <cstdio>
#include "seqlist.h"

using namespace std;

struct Student
{
	char name[32];
	int age;
};

int main()
{
	Student s1, s2, s3;
	s1.age = 21;
	s2.age = 22;
	s3.age = 23;

	int ret = 0;
	SeqList *list;

	list = SeqList_Create(10);

	ret = SeqList_Insert(list, (SeqListNode *)&s1, 0); // 头插法
	ret = SeqList_Insert(list, (SeqListNode *)&s2, 0); // 头插法
	ret = SeqList_Insert(list, (SeqListNode *)&s3, 0); // 头插法

	// 遍历链表
	for (int i = 0; i < SeqList_Length(list); ++i) {
		Student *tmp = (Student *)SeqList_Get(list, i);
		if (tmp == NULL) {
			printf("function SeqList_Get() err: %d\n", ret);
			return 0;
		}
		printf("age:%d\n", tmp->age);
	}

	// 销毁链表
	while (SeqList_Length(list)) {
		Student *tmp = (Student *)SeqList_Delete(list, 0);
		if (tmp == NULL) {
			printf("function SeqList_Delete() err: %d\n", ret);
			return 0;
		}
		printf("age:%d\n", tmp->age);
	}

	SeqList_Destroy(list);

	return 0;
}