#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "../StackAndQueue/LinkQueue.h"
#include <queue>

template<class T>
class LinkBinaryTree
{
	struct Node
	{
		T data;
		Node* lChild;
		Node* rChild;
		Node(T data)
		{
			this->data = data;
			lChild = rChild = NULL;
		}
	};
protected:
	Node* root;
	Node* createStrNode(LinkQueue<std::string>* datas,bool isInput = false)
	{
		std::string inputStr;
		if (isInput)
		{
			std::cout << "���������ݣ�#������:";
			std::getline(std::cin, inputStr);
		}
		else
		{
			inputStr = datas->deQueue();
		}
		Node *node;
		if (inputStr == "#")
			return NULL;
		else
		{
			node = new Node(inputStr);
			node->lChild = createStrNode(datas,isInput);
			node->rChild = createStrNode(datas,isInput);
			return node;
		}
	}

	void preTraverse(Node* node)//ǰ�����
	{
		if (node)
		{
			std::cout << node->data << ",";
			preTraverse(node->lChild);
			preTraverse(node->rChild);
		}
	}

	void midTraverse(Node* node)//�������
	{
		if (node)
		{
			midTraverse(node->lChild);
			std::cout << node->data << ",";
			midTraverse(node->rChild);
		}
	}

	void postTraverse(Node* node)//��������
	{
		if (node)
		{
			postTraverse(node->lChild);
			postTraverse(node->rChild);
			std::cout << node->data << ",";
		}
	}

	void levelTraverse()//��α���
	{
		LinkQueue<Node*>* queue1=new LinkQueue<Node*>();
		LinkQueue<Node*>* queue2 = new LinkQueue<Node*>();
		if (root)
		{
			queue1->enQueue(root);
			while (!queue1->isEmpty())
			{
				do
				{
					Node* node = queue1->deQueue();
					std::cout << node->data<<",";
					if (node->lChild)
						queue2->enQueue(node->lChild);
					if (node->rChild)
						queue2->enQueue(node->rChild);
				}
				while (!queue1->isEmpty());
				//����queue1��queue2
				LinkQueue<Node*>* tmp = queue1;
				queue1 = queue2;
				queue2 = tmp;
			}
		}
		delete queue1, queue2;
	}

	void releaseTree(Node* node)//ͨ������������ɾ����
	{
		if (node)
		{
			releaseTree(node->lChild);
			releaseTree(node->rChild);
			delete node;
		}
	}
public:
	~LinkBinaryTree()//����������ɾ���������ͷſռ�
	{
		releaseTree(root);
	}
	void createTestStrTree(LinkQueue<std::string>* datas)//ͨ���ַ�������
	{
		this->root=createStrNode(datas);
	}

	void createInputStrTree()//ͨ���û�������������
	{
		this->root=createStrNode(NULL,true);
	}

	void print(int choice)
	{
		switch (choice) {
		case 0:
			preTraverse(root);
			break;
		case 1:
			midTraverse(root);
			break;
		case 2:
			postTraverse(root);
			break;
		case 3:
			levelTraverse();
			break;
		default:
			std::cout << "�����������";
		}
	}
};

