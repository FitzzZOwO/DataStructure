#pragma once
#include "../LinkList/LinkedList.h"

template<class T>
class LinkQueue:LinkList<T>
{
public:
	LinkQueue(T data[],int size)
	{
		for (int i=0;i<size;i++)
		{
			enQueue(data[i]);
		}
	}

	LinkQueue()//Ĭ�Ϲ��캯��
	{
		
	}
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

