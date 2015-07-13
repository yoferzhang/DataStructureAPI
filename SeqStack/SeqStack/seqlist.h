// seqlist.h
// 顺序存储结构线性表的API声明

#ifndef  __MY_SEQLIST_H__ 
#define __MY_SEQLIST_H__

typedef void SeqList;
typedef void SeqListNode;

//链表 创建
SeqList* SeqList_Create(int capacity);

//链表 销毁
void SeqList_Destroy(SeqList* list);

////链表 清空
void SeqList_Clear(SeqList* list);

//链表 长度
int SeqList_Length(SeqList* list);


//链表 容量 
int SeqList_Capacity(SeqList* list);

//链表 在某一个位置 插入元素
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//获取某一个位置的链表结点
SeqListNode* SeqList_Get(SeqList* list, int pos);

//删除某一个位置的结点
SeqListNode* SeqList_Delete(SeqList* list, int pos);


#endif  //__MY_SEQLIST_H__