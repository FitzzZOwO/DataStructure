#pragma once
/**������ʹ��ʾ��
 *
    LinkList<std::string> link_list;
	link_list.pushBack("0");
	link_list.pushBack("1");
	link_list.pushBack("2");
	link_list.insert(0,"3");
	link_list.remove(0);
	link_list.remove(1);
	std::cout <<"Ԫ��0���ڵ��±�Ϊ"<< link_list.indexOf("0")<<std::endl;
	for (int i=0;i<link_list.getLength();i++)
	{
		std::cout << link_list.get(i)<<",";
	}
 */
template<class T>
class LinkList
{
	struct Node//�ڵ㶨��
	{
		T data;
		Node* next;
		Node(T data) {
			this->data = data;
			next = NULL;
		}
	};
private:
	Node* head;
	int length;
protected:
	/**
	* ��ȡĳλ�õĽڵ�
	*/
	Node* getNode(int position)
	{
		if (!head || position < 0 || position >= length)
			throw std::out_of_range("position is out of range");
		else
		{
			Node* curNode = head;
			int tmp = 0;
			while (tmp<position)
			{
				curNode = curNode->next;
				tmp++;
			}
			return curNode;
		}
	}
public:
	LinkList()
	{
		this->head = NULL;
		this->length = 0;
	}
	/**
	* �����������˴���Ҫ�ͷ�����
	*/
	~LinkList()
	{
		Node* curNode = head;
		while (curNode)
		{
			Node* tmp = curNode->next;
			delete curNode;
			curNode = tmp;
		}
	}

	/**
	* ��ȡ����ĳ���
	*/
	int getLength()
	{
		return length;
	}

	/**
	* ��ȡpositionλ���µ�����
	*/
	T get(int position)
	{
		return getNode(position)->data;
	}

	/**
	* ������ĩβ׷��Ԫ��
	*/
	void pushBack(T data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
			head = newNode;
		else {
			getNode(length - 1)->next = newNode;
		}
		this->length++;
	}

	/**
	* ��positionλ������data����
	*/
	void insert(int position, T data)
	{
		Node* newNode = new Node(data);
		if (position == 0) {
			Node* oldFirst = head;
			head = newNode;
			head->next = oldFirst;
		}
		else {
			Node* node = getNode(position - 1);
			Node* nextNode = node->next;
			node->next = newNode;
			newNode->next = nextNode;
		}
		this->length++;
	}

	/*
	*�Ƴ������е�position�±��Ԫ�أ�������Ԫ��ֵ
	*/
	T remove(int position)
	{
		T data;
		if (position == 0) {
			Node* removeNode;
			removeNode = head;
			data = head->data;
			head = head->next;
			delete removeNode;
		}
		else if (position<length)
		{
			Node* node = getNode(position - 1);
			Node* positionNode = node->next;
			node->next = node->next->next;
			data = positionNode->data;
			delete positionNode;
		}
		length--;
		return data;
	}

	/**
	*�ҵ���һ������data������λ��
	*/
	int indexOf(T data) {
		Node* curNode = head;
		int position = 0;
		while (curNode != NULL)
		{
			if (curNode->data == data)
				return position;
			curNode = curNode->next;
			position++;
		}
		return -1;
	}
};

