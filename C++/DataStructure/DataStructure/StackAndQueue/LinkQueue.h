#pragma once
#include "../LinkList/LinkedList.h"

template<class T>
class LinkQueue:LinkList<T>
{
public:
	/**
	 * ��Ӳ���
	 */
	void enQueue(T data)
	{
		insert(length, data);
	}

	/**
	 * ���Ӳ���
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

