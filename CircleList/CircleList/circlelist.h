// circlelist.h
// 循环链表API声明

#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode *next;
}CircleListNode;

// 创建链表
CircleList* CircleList_Create();

// 销毁链表
void CircleList_Destroy(CircleList* list);

// 清空链表
void CircleList_Clear(CircleList* list);

// 获取链表的长度
int CircleList_Length(CircleList* list);

// 在pos位置插入结点node
int CircleList_Insert(CircleList* list,CircleListNode* node, int pos);

// 获取pos位置的结点
CircleListNode* CircleList_Get(CircleList* list, int pos);

// 删除pos位置的结点
CircleListNode* CircleList_Delete(CircleList* list, int pos);

// 根据结点的值进行数据删除
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

// 重置游标
CircleListNode* CircleList_Reset(CircleList* list);

// 获取当前游标所指结点
CircleListNode* CircleList_Current(CircleList* list);

// 将原始游标所指结点返回给上层，然后让游标移到下一个结点
CircleListNode* CircleList_Next(CircleList* list);

#endif