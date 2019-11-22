// DataStructure.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdexcept>
#include "BinaryTree/LinkBinaryTree.h"
using namespace std;

int main()
{
	string strDatas[] = { "A","B","D","#","#","E","#","#","C","#","F","#","#" };
	LinkQueue<string> *datas=new LinkQueue<string>(strDatas,13);
	LinkBinaryTree<string> binaryTree;
	binaryTree.createTestStrTree(datas);//�û��Լ����봴����
	//binaryTree.createInputStrTree();
	cout << "ǰ��������Ϊ��";
	binaryTree.print(0);
	cout << endl;
	cout << "����������Ϊ��";
	binaryTree.print(1);
	cout << endl;
	cout << "����������Ϊ��";
	binaryTree.print(2);
	cout << endl;
	cout << "��α������Ϊ��";
	binaryTree.print(3);
	cout << endl;
	delete datas;
    return 0;
}

