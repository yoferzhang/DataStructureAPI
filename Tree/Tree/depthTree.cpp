// operatorTree.cpp
// 对树的操作

#include <iostream>
#include <cstdio>

// 二叉树表示法
typedef struct BiTNode
{
	int	data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 中序遍历
void inOrder(BiTNode *T)
{
	if (T == NULL) {
		return;
	}

	inOrder(T->lchild);

	printf("%d ", T->data);

	inOrder(T->rchild);
}

// 计算树的高度
int depthTree(BiTNode *T)
{
	if (!T) {
		return 0;
	}

	int depthVal = 0;
	int depthLeft = 0, depthRight = 0;

	depthLeft = depthTree(T->lchild);
	depthRight = depthTree(T->rchild);

	depthVal = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	return depthVal;
}

// copy二叉树
BiTNode* copyTree(BiTNode *T)
{
	if (T == NULL) {
		return NULL;
	}

	BiTNode *newNode = (BiTNode *)malloc(sizeof(BiTNode));
	if (newNode == NULL) {
		free(newNode);
		return NULL;
	}
	newNode->data = T->data;
	newNode->lchild = copyTree(T->lchild);
	newNode->rchild = copyTree(T->rchild);

	return newNode;
}

void operatorTree()
{
	BiTNode nodeA, nodeB, nodeC, nodeD, nodeE;

	memset(&nodeA, 0, sizeof(BiTNode));
	memset(&nodeB, 0, sizeof(BiTNode));
	memset(&nodeC, 0, sizeof(BiTNode));
	memset(&nodeD, 0, sizeof(BiTNode));
	memset(&nodeE, 0, sizeof(BiTNode));

	nodeA.data = 1;
	nodeB.data = 2;
	nodeC.data = 3;
	nodeD.data = 4;
	nodeE.data = 5;

	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeC;
	nodeB.lchild = &nodeD;
	nodeC.lchild = &nodeE;

	int depth = depthTree(&nodeA);
	printf("Depth: %d\n", depth);
	// Depth: 3

	BiTNode *newTree = NULL;
	newTree = copyTree(&nodeA);
	printf("inorder traversal new tree.\n");
	inOrder(&nodeA);
	// 4 2 1 5 3
	printf("\n");
}

int main()
{
	operatorTree();

	return 0;
}