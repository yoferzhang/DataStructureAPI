// seqstack.h
// 顺序存储结构的栈API声明

#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

typedef void SeqStack;

// 创建栈
SeqStack* SeqStack_Create(int capacity);

// 销毁栈
void* SeqStack_Destroy(SeqStack* stack);

// 清空栈
void* SeqStack_Clear(SeqStack* stack);

// 元素入栈
int SeqStack_Push(SeqStack* stack, void* item);

// 弹出栈顶元素
void* SeqStack_Pop(SeqStack* stack);

// 获取栈顶元素
void* SeqStack_Top(SeqStack* stack);

// 获取栈的大小
int SeqStack_Size(SeqStack* stack);

// 获取栈的容量
int SeqStack_Capacity(SeqStack* stack);

#endif