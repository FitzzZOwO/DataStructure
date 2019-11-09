#pragma once
#include "../LinkList/LinkedList.h"
template<class T>
class LinkStack:LinkList<T>
{
public:
	/*
	 * ��д���뷽����ʹ��ͷ�巨
	 */
	void pushBack(T data)
	{
		insert(0, data);
	}

	T pop()
	{
		if(this->head)
		{
			return remove(0);
		}
		return NULL;
	}
};

