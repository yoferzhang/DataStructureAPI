// linklist.cpp

#include <iostream>
#include <cstdio>
#include "linklist.h"

using namespace std;

typedef void LinkList;

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList *tmp = NULL;

	tmp = (TLinkList *)malloc(sizeof(TLinkList));
	if (tmp == NULL) {
		printf("function LinkList_Create() err.\n");
		return NULL;
	}
	memset(tmp, 0, sizeof(TLinkList)); // 初始化为空链表

	return tmp;
}

void LinkList_Destroy(LinkList* list)
{
	if (list == NULL) {
		return;
	}
	free(list);

	return;
}

void LinkList_Clear(LinkList* list)
{
	if (list == NULL) {
		return;
	}
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	tList->header.next = NULL;
	tList->length = 0;

	return;
}

int LinkList_Length(LinkList* list)
{
	if (list == NULL) {
		return -1;
	}
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;

	return tList->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	if (list == NULL || node == NULL || pos < 0) {
		return -1;
	}
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	LinkListNode *cur = NULL;
	cur = &(tList->header);

	// 对pos的容错处理，如果pos过大，改为最后面
	if (pos > LinkList_Length(list)) {
		pos = LinkList_Length(list);
	}

	// 移动到需要插入的位置
	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	// 插入
	node->next = cur->next;
	cur->next = node;

	++tList->length;

	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	if (list == NULL || pos < 0 || pos >= LinkList_Length(list)) {
		return NULL;
	}
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	LinkListNode *cur = NULL;
	cur = &(tList->header);

	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	return cur->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	if (list == NULL || pos < 0 || pos >= LinkList_Length(list)) {
		return NULL;
	}
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	LinkListNode *cur = NULL;
	cur = &(tList->header);

	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	LinkListNode *ret = NULL;
	ret = cur->next;

	// 删除结点
	cur->next = ret->next;

	--tList->length;

	return ret;
}
