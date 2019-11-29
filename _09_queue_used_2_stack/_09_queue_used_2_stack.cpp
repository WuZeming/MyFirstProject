// _09_queue_used_2_stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stack>
#include<exception>
template<typename T>
class CQueue
{
public:
	CQueue();
	~CQueue();
	void appendTail(const T&);
	T deleteHead();
private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template<typename T>
CQueue<T>::CQueue()
{
}

template<typename T>
CQueue<T>::~CQueue()
{
}


template<typename T>
void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	if (stack2.empty())
	{
		throw std::exception("queue is empty");
	}
	T ret = stack2.top();
	stack2.pop();
	return ret;
}

// ====================测试代码====================
void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');

	return 0;
}
