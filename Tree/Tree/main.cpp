// main.cpp
// 数的表示法

#include <iostream>
#include <cstdio>

// 二叉树表示法
typedef struct BiTNode
{
	int	data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


// 三叉链表表示法
typedef struct TriTNode
{
	int data;
	
	// 左右孩子指针
	TriTNode *lchild, *rchild;
	// 父指针
	TriTNode *parent;
}TriTNode, *TriTree;


// 双亲链表表示法
typedef struct BPTNode
{
	int data;
	int parentPosition; // 指向双亲的指针，数组下标
	char LRTag; // 左右孩子指标域
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100]; // 因为结点之间是分散的，需要把结点存储到数组中
	int numOfNode; // 结点数目
	int root; // 根节点位置，注意此域存储的是父亲节点在数组的下标
};


int main()
{

	return 0;
}