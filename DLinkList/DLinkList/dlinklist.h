// dlinklist.h
// 双向链表API声明

#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

typedef void DLinkList;

typedef struct _tag_DLinkListNode
{
	_tag_DLinkListNode *next;
	_tag_DLinkListNode *pre;
}DLinkListNode;

// 创建链表
DLinkList* DLinkList_Create();

// 销毁链表
void DLinkList_Destroy(DLinkList *list);

// 清空链表
void DLinkList_Clear(DLinkList *list);

// 获取链表长度
int DLinkList_Length(DLinkList *list);

// 在pos位置，插入结点node
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos);

// 获取pos位置的结点，返回给上层
DLinkListNode* DLinkList_Get(DLinkList *list, int pos);

// 删除pos位置的结点
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos);

// 删除值为node的结点
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);

// 重置游标
DLinkListNode* DLinkList_Reset(DLinkList* list);

// 获取当前游标所指的结点
DLinkListNode* DLinkList_Current(DLinkList* list);

// 获取游标当前所指结点，然后让游标指向下一个结点
DLinkListNode* DLinkList_Next(DLinkList* list);

// 获取游标当前所指结点，然后让游标指向前一个结点
DLinkListNode* DLinkList_Pre(DLinkList* list);


#endif