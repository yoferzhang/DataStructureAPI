// joseph.h
// 用循环链表API求解约瑟夫问题

#include <cstdio>
#include "circlelist.h"

const int maxp = 8;

struct Person
{
	CircleListNode circlenode;
	int id;
};

void joseph()
{
	Person s[maxp];
	for (int i = 0; i < maxp; ++i) {
		s[i].id = i + 1;
	}

	CircleList *list = NULL;
	list = CircleList_Create();

	// 插入元素
	for (int i = 0; i < maxp; ++i) {
		// 尾插法
		int ret = CircleList_Insert(list, (CircleListNode *)&s[i], CircleList_Length(list));
		if (ret < 0) {
			printf("function CircleList_Insert err: %d\n", ret);
		}
	}

	// 遍历链表
	for (int i = 0; i < CircleList_Length(list); ++i) {
		Person *tmp = (Person *)CircleList_Get(list, i);
		if (tmp == NULL) {
			printf("function CircleList_Get err.\n");
		}
		printf("age: %d\n", tmp->id);
	}

	// 求解约瑟夫问题
	while (CircleList_Length(list) > 0)
	{
		Person* pv = NULL;
		for (int i = 1; i < 3; i++)
		{
			CircleList_Next(list);
		}
		pv = (Person*)CircleList_Current(list);
		printf("%d ", pv->id);
		CircleList_DeleteNode(list, (CircleListNode *)pv); //根据结点的值,进行结点元素的删除
	}
	printf("\n");

	CircleList_Destroy(list);

}