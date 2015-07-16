// main.cpp
// 队列链式存储API测试程序

#include <stdio.h>
#include "linkqueue.h"

const int maxn = 10;

void play()
{
	int i = 0, a[maxn];
	LinkQueue *lq = NULL;

	for (i = 0; i < maxn; ++i) {
		a[i] = i + 1;
	}

	lq = LinkQueue_Create(); // 创建队列

	// 入队列
	for (i = 0; i < maxn; ++i) {
		LinkQueue_Append(lq, &a[i]);
	}

	// 队列属性
	printf("header: %d\n", *((int *)LinkQueue_Header(lq)));
	printf("length: %d\n", LinkQueue_Length(lq));

	// 出队列
	while (LinkQueue_Length(lq)) {
		int tmp = *((int *)LinkQueue_Retrieve(lq));
		printf("%d\n", tmp);
	}

	// 销毁队列
	LinkQueue_Destroy(lq);
}

int main()
{
	play();

	return 0;
}