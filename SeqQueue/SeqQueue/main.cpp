// main.cpp
// 顺序存储队列API的测试程序

#include <stdio.h>
#include "seqqueue.h"

const int maxn = 10;

void play()
{
	int i = 0, a[maxn];
	SeqQueue *sq = NULL;

	for (i = 0; i < maxn; ++i) {
		a[i] = i + 1;
	}

	sq = SeqQueue_Create(20); // 创建队列

	// 入队列
	for (i = 0; i < maxn; ++i) {
		SeqQueue_Append(sq, &a[i]);
	}

	// 获取队列属性
	printf("header: %d\n", *((int *)SeqQueue_Header(sq)));
	printf("length: %d\n", SeqQueue_Length(sq));
	printf("capacity: %d\n", SeqQueue_Capacity(sq));

	// 出队列
	while (SeqQueue_Length(sq)) {
		int tmp = *((int *)SeqQueue_Retrieve(sq));
		printf("%d\n", tmp);
	}
	SeqQueue_Destroy(sq);

}

int main()
{
	play();

	return 0;
}