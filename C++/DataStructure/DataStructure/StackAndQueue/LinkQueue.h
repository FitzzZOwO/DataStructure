#pragma once
#include "../LinkList/LinkedList.h"

template<class T>
class LinkQueue:LinkList<T>
{
public:
	/**
	 * 入队操作
	 */
	void enQueue(T data)
	{
		insert(length, data);
	}

	/**
	 * 出队操作
	 */
	T deQueue()
	{
		if (!isEmpty())
		{
			return this->remove(0);
		}
		return NULL;
	}

	bool isEmpty()
	{
		return this->length == 0;
	}
};

