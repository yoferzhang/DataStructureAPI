// linkqueue.cpp
// 队列链式存储API实现
// 调用了链式存储线性表

#include <stdio.h>
#include "linkqueue.h"
#include "linklist.h"
#include <malloc.h>

typedef struct _tag_LinkQueue
{
	LinkListNode node;
	void* item;
}TLinkQueue;

// 创建队列相当于创建链表
LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

// 销毁队列相当于创建链表
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

// 清空队列相当于清空链表
void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue)) {
		LinkQueue_Retrieve(queue);
	}
}

// 入队列相当于在链表尾部插入元素
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	TLinkQueue *tmp = NULL;
	int ret = 0;

	tmp = (TLinkQueue *)malloc(sizeof(TLinkQueue));
	if (tmp == NULL) { // 分配失败
		return -1;
	}

	tmp->item = item;

	ret = LinkList_Insert(queue, (LinkListNode *)tmp, LinkList_Length(queue));
	if (ret) {
		printf("function LinkQueue_Append err: %d\n", ret);
		free(tmp);
		return ret;
	}

	return ret;
}

// 出队列相当于删除链表0号位置的元素
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueue *tmp = NULL;
	void* item = NULL;
	tmp = (TLinkQueue *)LinkList_Delete(queue, 0);
	if (tmp == NULL) {
		return NULL;
	}

	item = tmp->item;
	free(tmp); // 不要忘记出队列的时候释放结点
		
	return item;
}

// 获取队头元素相当于获取链表0号位置元素
void* LinkQueue_Header(LinkQueue* queue)
{
	TLinkQueue *tmp = NULL;
	tmp = (TLinkQueue *)LinkList_Get(queue, 0);
	if (tmp == NULL) {
		return NULL;
	}
	return tmp->item;
}

// 获取队列长度
int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}