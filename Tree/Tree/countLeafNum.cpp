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

// 计算叶子结点个数
int sum1 = 0;
void countLeafNum1(BiTNode *T)
{
	if (T == NULL) {
		return;
	}
	if (T->lchild == NULL && T->rchild == NULL) {
		sum1++;
	}

	countLeafNum1(T->lchild);

	countLeafNum1(T->rchild);
}

// 1递归函数遇到全局变量，最好转化成函数参数
// 2遍历的本质强化
// 访问树的路径是相同，只不过是计算叶子结点的时机不同。
void countLeafNum2(BiTNode *T, int *sum)
{
	if (T == NULL) {
		return;
	}
	if (T->lchild == NULL && T->rchild == NULL) {
		(*sum)++;
	}

	countLeafNum2(T->lchild, sum);

	countLeafNum2(T->rchild, sum);
}

void countLeafNum3(BiTNode *T, int *sum)
{
	if (T == NULL) {
		return;
	}

	countLeafNum3(T->lchild, sum);

	countLeafNum3(T->rchild, sum);

	if (T->lchild == NULL && T->rchild == NULL) {
		(*sum)++;
	}

}


void countLeaf()
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

	countLeafNum1(&nodeA);
	printf("sum1: %d\n", sum1);
	// sum1: 2

	int sum2 = 0;
	countLeafNum2(&nodeA, &sum2);
	printf("sum2: %d\n", sum2);
	// sum2: 2

	int sum3 = 0;
	countLeafNum3(&nodeA, &sum3);
	printf("sum3: %d\n", sum3);
	// sum3: 2

}

int main()
{
	countLeaf();

	return 0;
}