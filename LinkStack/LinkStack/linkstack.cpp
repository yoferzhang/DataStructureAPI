// linkstack.cpp
// 链式存储栈的API实现

#include <stdio.h>
#include <malloc.h>
#include "linkstack.h"
#include "linklist.h"

typedef void LinkStack;

typedef struct _tag_LinkStack
{
	LinkListNode node;
	void* item;
}TLinkStack;

// 创建一个栈，相当于创建一个线性表
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

// 销毁栈
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack); // 释放栈的结点
	LinkList_Destroy(stack); // 释放句柄
	return;
}

// 清空栈
void LinkStack_Clear(LinkStack* stack)
{
	while (LinkList_Length(stack)) {
		LinkStack_Pop(stack);
	}
	return;
}

// 向栈中添加元素，相当于用头插法向线性表添加结点
int LinkStack_Push(LinkStack* stack, void* item)
{
	int ret = 0;
	TLinkStack *tStack = NULL;

	// 把void* item转化成链表结点
	tStack = (TLinkStack *)malloc(sizeof(TLinkStack));
	tStack->item = item;

	// 头插法插入结点
	ret = LinkList_Insert(stack, (LinkListNode *)tStack, 0);
	if (ret) {
		printf("function LinkStack_Push err: %d.\n", ret);
		free(tStack);
		return ret;
	}

	return ret;
}

// 弹出栈顶元素，相当于从线性表中删除0号元素
void* LinkStack_Pop(LinkStack* stack)
{
	TLinkStack *tStack = NULL;
	void* item = NULL;

	tStack = (TLinkStack *)LinkList_Delete(stack, 0);
	if (tStack == NULL) {
		printf("function LinkStack_Pop err.\n");
		return NULL;
	}

	// 把链表结点转化成栈结点
	item = tStack->item;
	free(tStack); // 记得释放创建时候malloc的内存

	return item;
}

// 获取栈顶元素
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStack *tStack = NULL;
	void* item = NULL;

	tStack = (TLinkStack *)LinkList_Get(stack, 0);
	if (tStack == NULL) {
		printf("function LinkStack_Top err.\n");
		return NULL;
	}

	item = tStack->item;

	return item;
}

// 获取栈的大小
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}