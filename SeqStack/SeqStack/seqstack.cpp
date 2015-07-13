// seqstack.cpp
// 顺序存储结构栈的API实现
// 调用了之前写好的顺序链表API

#include <cstdio>
#include "seqlist.h"
#include "seqstack.h"

// 创建栈，相当于创建一个线性表
SeqStack* SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}

// 销毁栈，相当于销毁链表
void* SeqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);

	return NULL;
}

// 清空栈，相当于清空链表
void* SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
	return NULL;
}

// 元素入栈，相当于在线性表（数组）的尾部添加元素
int SeqStack_Push(SeqStack* stack, void* item)
{
	return SeqList_Insert(stack, item, SeqList_Length(stack));
}

// 弹出栈顶元素，相当于从线性表的尾部删除元素
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

// 获取栈顶元素，相当于获取链表的尾部元素
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

// 获取栈的大小，相当于获取链表的长度
int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

// 获取栈的容量
int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}