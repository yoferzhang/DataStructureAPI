// linklist.h

#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
struct Node
{
	T t;
	Node<T> *next;
};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();

public:
	int clear();
	int insert(T &t, int pos);
	int get(int pos, T &t);
	int del(int pos, T &t);
	int getLen();

protected:
	Node<T> *header;
	int length;
};

template <typename T>
LinkList<T>::LinkList()
{
	header = new Node < T > ;
	header->next = NULL;
	length = 0;
}

template <typename T>
LinkList<T>::~LinkList()
{
	Node<T> *tmp = NULL;

	while (header) {
		tmp = header->next;
		delete header;
		header = tmp;
	}
}

template <typename T>
int LinkList<T>::clear()
{
	~LinkList();
	LinkList();
	return 0;
}

template <typename T>
int LinkList<T>::insert(T &t, int pos)
{
	Node<T> *cur = NULL;

	// 对pos的容错处理
	if (pos >= length) {
		pos = length;
	}

	cur = header;
	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	// 把上层应用的t结点缓存到容器中
	Node<T> *node = new Node < T > ;
	node->next = NULL;
	node->t = t; // 把t缓存到容器中

	node->next = cur->next;
	cur->next = node;

	++length;

	return 0;
}

template <typename T>
int LinkList<T>::get(int pos, T &t)
{
	Node<T> *cur = NULL;

	if (pos >= length) {
		return -1;
	}

	cur = header;
	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	t = cur->next->t; // 把pos位置的结点赋值给t

	return 0;
}

template <typename T>
int LinkList<T>::del(int pos, T &t)
{
	Node<T> *cur = NULL;

	if (pos >= length) {
		return -1;
	}

	cur = header;
	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}
	Node<T> *ret = NULL;
	ret = cur->next;
	t = ret->t; // 把缓存的结点给上层应用t

	// 删除操作
	cur->next = ret->next;
	--length;
	delete ret; // 注意释放内存，因为insert的时候new Node<T>

	return 0;
}

template <typename T>
int LinkList<T>::getLen()
{
	return length;
}