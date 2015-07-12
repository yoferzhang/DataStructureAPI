// circlelist.cpp
// 循环链表API实现

#include <iostream>
#include <cstdio>
#include "circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode *silder;
	int length;
}TCircleList;

// 创建链表
CircleList* CircleList_Create()
{
	TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
	if (ret == NULL) {
		return NULL;
	}

	// 初始化
	ret->header.next = NULL;
	ret->silder = NULL;
	ret->length = 0;

	return ret;
}

// 销毁链表
void CircleList_Destroy(CircleList* list)
{
	if (list == NULL) {
		return;
	}
	free(list);
	return;
}

// 清空链表
void CircleList_Clear(CircleList* list)
{
	if (list == NULL) {
		return;
	}
	TCircleList *tList = (TCircleList *)list;
	tList->header.next = NULL;
	tList->silder = NULL;
	tList->length = 0;

	return;
}

// 获取链表的长度
int CircleList_Length(CircleList* list)
{
	if (list == NULL) {
		return -1;
	}
	TCircleList *tList = (TCircleList *)list;
	return tList->length;
}

// 在pos位置插入结点node
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	if (list == NULL || node == NULL || pos < 0) {
		return -1;
	}

	TCircleList *tList = (TCircleList *)list;

	CircleListNode *cur = (CircleListNode *)tList;

	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	node->next = cur->next;
	cur->next = node;

	// 如果是第一次插入
	if (tList->length == 0) {
		tList->silder = node;
	}

	++tList->length; // 记得长度加1

	// 如果是头插法
	if (cur == (CircleListNode *)tList) {
		// 获取最后一个元素
		CircleListNode *last = CircleList_Get(tList, tList->length - 1);
		last->next = cur->next;
	}

	return 0;
}

// 获取pos位置的结点
CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	// 因为是循环链表，所以这里不需要排除pos>length的情况
	if (list == NULL || pos < 0) {
		return NULL;
	}

	TCircleList *tList = (TCircleList *)list;
	CircleListNode *cur = (CircleListNode *)tList;

	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	return cur->next;
}

// 删除pos位置的结点
CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode *ret = NULL;

	if (tList != NULL && pos >= 0 && tList->length > 0) {
		CircleListNode *cur = (CircleListNode *)tList;
		for (int i = 0; i < pos; ++i) {
			cur = cur->next;
		}

		// 若删除头结点，需要求出尾结点
		CircleListNode *last = NULL;
		if (cur == (CircleListNode *)tList)  {
			last = CircleList_Get(tList, tList->length - 1);
		}

		ret = cur->next;
		cur->next = ret->next;

		--tList->length;

		// 若删除头结点
		if (last != NULL) {
			tList->header.next = ret->next;
			last->next = ret->next;
		}

		// 若删除的元素为游标所指的元素
		if (tList->silder == ret) {
			tList->silder = ret->next;
		}

		// 若删除元素后链表长度为0
		if (tList->length == 0) {
			tList->header.next = NULL;
			tList->silder = NULL;
		}
	}

	return ret;
}

// 根据结点的值进行数据删除
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode *ret = NULL;

	if (list != NULL && node != NULL) {
		CircleListNode *cur = (CircleListNode *)tList;
		int i = 0;
		for (i = 0; i < tList->length; ++i) {
			if (cur->next == node) {
				ret = cur->next;
				break;
			}

			cur = cur->next;
		}

		// 如果找到
		if (ret != NULL) {
			CircleList_Delete(tList, i);
		}
	}

	return ret;
}

// 重置游标
CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode* ret = NULL;

	if (list != NULL) {
		tList->silder = tList->header.next;
		ret = tList->silder;
	}

	return NULL;
}

// 获取当前游标所指结点
CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode* ret = NULL;
	if (list != NULL) {
		ret = tList->silder;
	}

	return ret;
}

// 将原始游标所指结点返回给上层，然后让游标移到下一个结点
CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode* ret = NULL;
	if (list != NULL && tList->silder != NULL) {
		ret = tList->silder;
		tList->silder = ret->next;
	}
	return ret;
}