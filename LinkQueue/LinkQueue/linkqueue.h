// linkqueue.h
// 队列链式存储API声明

#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

typedef void LinkQueue;

// 创建队列
LinkQueue* LinkQueue_Create();

// 销毁队列
void LinkQueue_Destroy(LinkQueue* queue);

// 清空队列
void LinkQueue_Clear(LinkQueue* queue);

// 入队列
int LinkQueue_Append(LinkQueue* queue, void* item);

// 出队列
void* LinkQueue_Retrieve(LinkQueue* queue);

// 获取对头元素
void* LinkQueue_Header(LinkQueue* queue);

// 获取队列长度
int LinkQueue_Length(LinkQueue* queue);

#endif //_MY_LINKQUEUE_H_
