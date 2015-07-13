// seqList.cpp
// 顺序存储结构的栈API实现

#include <iostream>
#include <cstdio>
#include "seqlist.h"

using namespace std;

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	int **node;
}TSeqList;

//链表 创建
SeqList* SeqList_Create(int capacity)
{
	int ret = -1;
	TSeqList *tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL) {
		ret = 1;
		printf("function SeqList_Create() err:%d\n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;
	tmp->node = (int **)malloc(sizeof(void *) * capacity);
	if (tmp->node == NULL) {
		ret = 2;
		printf("function SeqList_Create() err:%d\n", ret);
		return NULL;
	}
	memset(tmp->node, 0, sizeof(void *) * capacity);

	return tmp;
}

//链表 创建
int SeqList_Create2(int capacity, SeqList**handle)
{
	int			ret = 0;
	TSeqList	*tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = 1;
		printf("func SeqList_Create2() err :%d \n", ret);
		return ret;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;
	tmp->node = (int **)malloc(sizeof(void *) * capacity);
	if (tmp->node == NULL)
	{
		ret = 2;
		printf("func SeqList_Create2() malloc err :%d \n", ret);
		return ret;
	}

	*handle = tmp;
	return ret;
}

//链表 销毁
void SeqList_Destroy(SeqList* list)
{
	if (list == NULL) {
		return;
	}

	TSeqList *tmp = (TSeqList *)list;
	if (tmp->node != NULL) {
		free(tmp->node);
	}
	free(tmp);

	return;
}

////链表 清空
void SeqList_Clear(SeqList* list)
{
	if (list == NULL) {
		return;
	}

	TSeqList *tmp = (TSeqList *)list;
	tmp->length = 0;
	memset(tmp->node, 0, sizeof(tmp->node));

	return;
}

//链表 长度
int SeqList_Length(SeqList* list)
{
	if (list == NULL) {
		return -1;
	}

	TSeqList *tmp = (TSeqList *)list;
	return tmp->length;
}

//链表 容量 
int SeqList_Capacity(SeqList* list)
{
	if (list == NULL) {
		return -1;
	}

	TSeqList *tmp = (TSeqList *)list;
	return tmp->capacity;
}

//链表 在某一个位置 插入元素
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	if (list == NULL || node == NULL || pos < 0) {
		return -1;
	}

	TSeqList *tList = (TSeqList *)list;

	// 如果满了
	if (tList->length >= tList->capacity) {
		return -2;
	}

	// 如果pos的位置超出了length，即中间空了一些位置
	if (pos > tList->length) {
		pos = tList->length;
	}

	for (int i = tList->length; i > pos; --i) {
		tList->node[i] = tList->node[i - 1];
	}
	tList->node[pos] = (int *)node;
	++tList->length;

	return 0;
}

//获取某一个位置的链表结点
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList *tList = (TSeqList *)list;
	if (list == NULL || pos < 0 || pos >= tList->length)
	{
		return NULL;
	}

	SeqListNode *tListNode = NULL;
	tListNode = (int *)tList->node[pos];

	return tListNode;
}

//删除某一个位置的结点
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList *tList = (TSeqList *)list;
	SeqListNode *tListNode = NULL;
	if (list == NULL || pos < 0 || pos >= tList->length) {
		return NULL;
	}

	tListNode = tList->node[pos];
	for (int i = pos + 1; i < tList->length; ++i) {
		tList->node[i - 1] = tList->node[i];
	}
	--tList->length; // 别忘了长度减一

	return tListNode;
}