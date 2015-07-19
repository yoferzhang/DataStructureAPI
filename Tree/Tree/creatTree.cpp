// creatTree.cpp
// 对树的操作

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

// 二叉树表示法
typedef struct BiTNode
{
	int	data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 递归中序遍历
void inOrder(BiTNode *T)
{
	if (T == NULL) {
		return;
	}

	inOrder(T->lchild);

	printf("%c ", T->data);

	inOrder(T->rchild);
}

// #号法创建树
BiTNode* BiTNodeCreate()
{
	BiTNode *tmp = NULL;
	char ch;
	scanf("%c", &ch);

	if (ch == '#') {
		return NULL;
	}
	else {
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if (tmp == NULL) {
			return NULL;
		}
		tmp->data = ch;
		tmp->lchild = BiTNodeCreate();
		tmp->rchild = BiTNodeCreate();
		return tmp;
	}
}

// 释放树，先释放左子树，再释放右子树，再释放根结点
void BiTNodeFree(BiTNode *T)
{
	if (!T) {
		return;
	}

	if (T->lchild) {
		BiTNodeFree(T->lchild);
		T->lchild = NULL;
	}

	if (T->lchild) {
		BiTNodeFree(T->lchild);
		T->lchild = NULL;
	}

	free(T);
}

void operatorTree()
{
	BiTNode *T = NULL;
	T = BiTNodeCreate();

	inOrder(T);
	printf("\n");
	BiTNodeFree(T);
}

int main()
{
	operatorTree();

	return 0;
}