// seqqueue.h
// 顺序存储队列API声明

#ifndef _MY_SEQQUEUE_H_
#define _MY_SEQQUEUE_H_

typedef void SeqQueue;

//  创建队列
SeqQueue* SeqQueue_Create(int capacity);

// 销毁队列
void SeqQueue_Destroy(SeqQueue* queue);

// 清空队列
void SeqQueue_Clear(SeqQueue* queue);

// 入队列
int SeqQueue_Append(SeqQueue* queue, void* item);

// 出队列
void* SeqQueue_Retrieve(SeqQueue* queue);

// 获取对头元素
void* SeqQueue_Header(SeqQueue* queue);

// 获取队列长度
int SeqQueue_Length(SeqQueue* queue);

// 获取队列容量
int SeqQueue_Capacity(SeqQueue* queue);

#endif //_MY_SEQQUEUE_H_
