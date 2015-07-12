// dlinklist.cpp
// 循环链表API实现

#include <cstdio>
#include <malloc.h>
#include "dlinklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}TDLinkList;

// 创建链表
DLinkList* DLinkList_Create()
{
	TDLinkList *ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	
	if (ret != NULL) {
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
		ret->length = 0;
	}

	return ret;
}

// 销毁链表
void DLinkList_Destroy(DLinkList *list)
{
	if (list != NULL) {
		free(list);
	}

	return;
}

// 清空链表
void DLinkList_Clear(DLinkList *list)
{
	TDLinkList *tList = (TDLinkList *)list;

	if (tList != NULL) {
		tList->header.next = NULL;
		tList->header.pre = NULL;
		tList->slider = NULL;
		tList->length = 0;
	}
	
	return;
}

// 获取链表长度
int DLinkList_Length(DLinkList *list)
{
	TDLinkList *tList = (TDLinkList *)list;
	int ret = -1;

	if (tList != NULL) {
		ret = tList->length;
	}

	return ret;
}

// 在pos位置，插入结点node
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos)
{
	TDLinkList *tList = (TDLinkList *)list;
	int ret = -1, i = 0;

	if (list != NULL && node != NULL && pos >= 0)
	{
		ret = 0;

		DLinkListNode *cur = (DLinkListNode *)tList;
		DLinkListNode *next = NULL;

		for (i = 0; i < pos && cur->next != NULL; ++i) {
			cur = cur->next;
		}

		next = cur->next;

		cur->next = node;
		node->next = next;

		// 当链表插入第一个结点时需要进行特殊处理
		if (next != NULL) {
			next->pre = node;
		}
		node->pre = cur;

		if (tList->length == 0)	 {
			tList->slider = node; // 当链表插入第一个元素处理游标
		}

		// 若在0位置插入，需要特殊处理，新来的结点next前pre指向NULL
		if (cur == (DLinkListNode *)tList) {
			node->pre = NULL;
		}
		++tList->length;
	}

	return ret;
}

// 获取pos位置的结点，返回给上层
DLinkListNode* DLinkList_Get(DLinkList *list, int pos)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	
	if (list != NULL && pos >= 0 && pos < tList->length) {
		DLinkListNode *cur = (DLinkListNode *)tList;

		for (i = 0; i < pos; ++i) {
			cur = cur->next;
		}

		ret = cur->next;
	}

	return ret;
}

// 删除pos位置的结点
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;
	int	i = 0;

	if (tList != NULL && pos >= 0) {
		DLinkListNode *cur = (DLinkListNode *)tList;
		DLinkListNode *next = NULL;

		for (i = 0; i < pos && cur->next != NULL; ++i) {
			cur = cur->next;
		}

		ret = cur->next;
		next = ret->next;

		cur->next = next;

		if (next != NULL) {
			next->pre = cur;

			if (cur == (DLinkListNode *)tList) { // 第0个位置，需要特殊处理
				next->pre = NULL;
			}
		}

		if (tList->slider == ret) {
			tList->slider = next;
		}

		--tList->length;
	}

	return ret;
}

// 删除值为node的结点
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;
	int	i = 0;

	if (tList != NULL) {
		DLinkListNode *cur = (DLinkListNode *)tList;

		for (i = 0; i < DLinkList_Length(tList); ++i) {
			if (cur->next == node) {
				ret = cur->next;
				break;
			}

			cur = cur->next;
		}

		if (!ret) {
			DLinkList_Delete(tList, i);
		}
	}

	return ret;
}

// 重置游标
DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;
	
	if (tList != NULL) {
		tList->slider = tList->header.next;
		ret = tList->slider;
	}

	return ret;
}

// 获取当前游标所指的结点
DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;

	if (tList != NULL) {
		ret = tList->slider;
	}

	return ret;
}

// 获取游标当前所指结点，然后让游标指向下一个结点
DLinkListNode* DLinkList_Next(DLinkList* list)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;

	if (tList != NULL && tList->slider != NULL) {
		ret = tList->slider;
		tList->slider = ret->next;
	}

	return ret;
}

// 获取游标当前所指结点，然后让游标指向前一个结点
DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;

	if (tList != NULL && tList->slider != NULL) {
		ret = tList->slider;
		tList->slider = ret->pre;
	}

	return ret;
}