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

// 先序遍历
void preOrder(BiTNode *T)
{
	if (T == NULL) {
		return;
	}

	printf("%d ", T->data);

	preOrder(T->lchild);

	preOrder(T->rchild);

}

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

// 后序遍历
void postOrder(BiTNode *T)
{
	if (T == NULL) {
		return;
	}

	postOrder(T->lchild);

	postOrder(T->rchild);

	printf("%d ", T->data);
}

void traversalTree()
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

	printf("preorder traversal.\n");
	preOrder(&nodeA);
	// 1 2 4 3 5
	printf("\n");

	printf("inorder traversal.\n");
	inOrder(&nodeA);
	// 4 2 1 5 3
	printf("\n");

	printf("postorder traversal.\n");
	postOrder(&nodeA);
	// 4 2 5 3 1
	printf("\n");
}

int main()
{
	traversalTree();

	return 0;
}