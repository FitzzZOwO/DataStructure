// DataStructure.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include "LinkList/LinkedList.h"
using namespace std;

int main()
{
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
	std::cout << std::endl;
    return 0;
}

