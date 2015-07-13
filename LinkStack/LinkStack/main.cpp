// main.cpp
// 栈链式存储的测试程序

#include <stdio.h>
#include "linkstack.h"
#include "scanner.h"

const int maxn = 5;

void play()
{
	int a[maxn];

	for (int i = 0; i < maxn; ++i) {
		a[i] = i + 1;
	}

	LinkStack *stack = NULL;

	stack = LinkStack_Create(); // 创建栈

	// 入栈
	for (int i = 0; i < maxn; ++i) {
		LinkStack_Push(stack, &a[i]);
	}

	// 栈属性
	printf("size: %d\n", LinkStack_Size(stack));
	printf("top: %d\n", *((int *)LinkStack_Top(stack)));

	LinkStack_Destroy(stack);
}

int main()
{
	play();
	playScanner();

	return 0;
}