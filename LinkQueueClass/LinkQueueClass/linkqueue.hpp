// linkqueue.hpp
// ∂”¡–¿‡

#pragma once

#include "linklist.hpp"

template <typename T>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();
public:
	int clear();
	int append(T &t);
	int retieve(T &t);
	int header(T &t);
	int length();
protected:
	LinkList<T> *m_list;
};

template <typename T>
LinkQueue<T>::LinkQueue()
{
	m_list = new LinkList < T > ;
}

template <typename T>
LinkQueue<T>::~LinkQueue()
{
	clear();
	delete m_list;
	m_list = NULL;
}

template <typename T>
int LinkQueue<T>::clear()
{
	T t;
	while (m_list->getLen() > 0) {
		m_list->del(0, t);
	}
	return 0;
}

template <typename T>
int LinkQueue<T>::append(T &t)
{
	return m_list->insert(t, m_list->getLen());
}

template <typename T>
int LinkQueue<T>::retieve(T &t)
{
	return m_list->del(m_list->getLen() - 1, t);
}

template <typename T>
int LinkQueue<T>::header(T &t)
{
	return m_list->get(0, t);
}

template <typename T>
int LinkQueue<T>::length()
{
	return m_list->getLen();
}
