// DataStructure.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include "StackAndQueue/LinkQueue.h"
using namespace std;

int main()
{
	LinkQueue<string> queue;
	queue.enQueue("0");
	queue.enQueue("1");
	queue.enQueue("2");
	cout << queue.deQueue() << endl;
	cout << queue.deQueue() << endl;
	cout << queue.deQueue() << endl;
    return 0;
}

