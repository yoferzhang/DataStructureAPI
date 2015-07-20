// linkstack.hpp
// ’ª¿‡

#pragma once

#include "linklist.hpp"

template <typename T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
public:
	int clear();
	int push(T &t);
	int pop(T &t);
	int top(T &t);
	int size();
protected:
	LinkList<T> *m_list;
};

template <typename T>
LinkStack<T>::LinkStack()
{
	m_list = new LinkList < T > ;
}

template <typename T>
LinkStack<T>::~LinkStack()
{
	clear();
	delete m_list;
	m_list = NULL;
}

template <typename T>
int LinkStack<T>::clear()
{
	T t;
	while (m_list->getLen() > 0) {
		m_list->del(0, t);
	}

	return 0;
}

template <typename T>
int LinkStack<T>::push(T &t)
{
	return m_list->insert(t, 0);
}

template <typename T>
int LinkStack<T>::pop(T &t)
{
	return m_list->del(0, t);
}

template <typename T>
int LinkStack<T>::top(T &t)
{
	return m_list->get(0, t);
}

template <typename T>
int LinkStack<T>::size()
{
	return m_list->getLen();
}