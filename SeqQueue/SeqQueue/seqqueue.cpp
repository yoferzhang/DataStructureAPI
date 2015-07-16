// seqqueue.cpp
// 顺序存储队列API实现
// 调用了顺序存储表的API

#include <stdio.h>
#include "seqqueue.h"
#include "seqlist.h"

// 创建队列相当于创建一个链表
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

// 销毁队列相当于销毁链表
void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
	return;
}

// 清空队列相当于清空链表
void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
	return;
}

// 入队列相当于在链表尾部插入元素
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqList_Insert(queue, item, SeqList_Length(queue));
}

// 出队列相当于删除链表0号位置的元素
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqList_Delete(queue, 0);
}

// 获取对头元素相当于获取链表0号位置元素
void* SeqQueue_Header(SeqQueue* queue)
{
	return SeqList_Get(queue, 0);
}

// 获取队列长度相当于获取链表长度
int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

// 获取队列容量相当于获取链表容量
int SeqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}