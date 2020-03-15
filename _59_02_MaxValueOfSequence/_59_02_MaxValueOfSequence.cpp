/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������59�����������е����ֵ
// ��Ŀ������һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ�����磬
// �����������{2, 3, 4, 2, 6, 2, 5, 1}���������ڵĴ�С3����ôһ������6��
// �������ڣ����ǵ����ֵ�ֱ�Ϊ{4, 4, 6, 6, 6, 5}��

#include <cstdio>
#include <deque>
#include <exception>

using namespace std;

template<typename T>
class QueueWithMax
{
public:
	QueueWithMax() : currIndex(0) { }
	void push_back(T number)
	{
		while (!maxIndex.empty() && maxIndex.back().number <= number)
		{
			maxIndex.pop_back();
		}
		InternalData num = { number, currIndex };
		maxIndex.push_back(num);
		currIndex++;
		data.push_back(num);
	}

	void pop_front()
	{
		if (data.empty())
		{
			throw new exception("queue empty");
		}
		if (!data.empty()&&data.front().index == maxIndex.front().index)
		{
			maxIndex.pop_front();
		}
		data.pop_front();
	}
	T max() const
	{
		if (maxIndex.empty())
		{
			throw new exception(" queue empty");
		}
		return maxIndex.front().number;
	}
private:
	struct InternalData
	{
		T number;
		int index;
	};
	deque<InternalData> data;
	deque<InternalData> maxIndex;
	int currIndex;

};
// ====================���Դ���====================
void Test(const char* testName, const QueueWithMax<int>& queue, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (queue.max() == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	QueueWithMax<int> queue;
	// {2}
	queue.push_back(2);
	Test("Test1", queue, 2);

	// {2, 3}
	queue.push_back(3);
	Test("Test2", queue, 3);

	// {2, 3, 4}
	queue.push_back(4);
	Test("Test3", queue, 4);

	// {2, 3, 4, 2}
	queue.push_back(2);
	Test("Test4", queue, 4);

	// {3, 4, 2}
	queue.pop_front();
	Test("Test5", queue, 4);

	// {4, 2}
	queue.pop_front();
	Test("Test6", queue, 4);

	// {2}
	queue.pop_front();
	Test("Test7", queue, 2);

	// {2, 6}
	queue.push_back(6);
	Test("Test8", queue, 6);

	// {2, 6, 2}
	queue.push_back(2);
	Test("Test9", queue, 6);

	// {2, 6, 2, 5}
	queue.push_back(5);
	Test("Test9", queue, 6);

	// {6, 2, 5}
	queue.pop_front();
	Test("Test10", queue, 6);

	// {2, 5}
	queue.pop_front();
	Test("Test11", queue, 5);

	// {5}
	queue.pop_front();
	Test("Test12", queue, 5);

	// {5, 1}
	queue.push_back(1);
	Test("Test13", queue, 5);

	return 0;
}