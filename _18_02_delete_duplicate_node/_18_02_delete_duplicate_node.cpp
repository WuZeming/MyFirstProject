// _18_02_delete_duplicate_node.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"../Utilities/List.h"



void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode* preNode = nullptr;
	ListNode* currNode = *pHead;
	*pHead = nullptr;
	while (currNode != nullptr)
	{
		if (currNode->m_pNext!= nullptr&& currNode->m_pNext->m_nValue == currNode->m_nValue)
		{
			//ѭ��ɾ�������ظ�
			int value = currNode->m_nValue;
			while (currNode!= nullptr && currNode->m_nValue == value)
			{
				ListNode* toBeDelete = currNode;
				currNode = currNode->m_pNext;
				delete toBeDelete;
			}
		}
		else
		{
			if (preNode == nullptr)
			{
				*pHead = currNode;
				preNode = currNode;
			}
			else
			{
				preNode->m_pNext = currNode;
				preNode = currNode;
			}

			currNode = currNode->m_pNext;
		}
	}

}


// ====================���Դ���====================
void Test(char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	DeleteDuplication(pHead);

	int index = 0;
	ListNode* pNode = *pHead;
	while (pNode != nullptr && index < expectedLength)
	{
		if (pNode->m_nValue != expectedValues[index])
			break;

		pNode = pNode->m_pNext;
		index++;
	}

	if (pNode == nullptr && index == expectedLength)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

// ĳЩ������ظ���
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(4);
	ListNode* pNode7 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 1, 2, 5 };
	Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// û���ظ��Ľ��
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// ����һ�����֮���������н���ֵ����ͬ
void Test3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(1);
	ListNode* pNode4 = CreateListNode(1);
	ListNode* pNode5 = CreateListNode(1);
	ListNode* pNode6 = CreateListNode(1);
	ListNode* pNode7 = CreateListNode(2);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 2 };
	Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// ���н���ֵ����ͬ
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(1);
	ListNode* pNode4 = CreateListNode(1);
	ListNode* pNode5 = CreateListNode(1);
	ListNode* pNode6 = CreateListNode(1);
	ListNode* pNode7 = CreateListNode(1);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	ListNode* pHead = pNode1;

	Test("Test4", &pHead, nullptr, 0);

	DestroyList(pHead);
}

// ���н�㶼�ɶԳ���
void Test5()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(2);
	ListNode* pNode5 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(3);
	ListNode* pNode7 = CreateListNode(4);
	ListNode* pNode8 = CreateListNode(4);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);
	ConnectListNodes(pNode7, pNode8);

	ListNode* pHead = pNode1;

	Test("Test5", &pHead, nullptr, 0);

	DestroyList(pHead);
}

// �����������֮��������㶼�ɶԳ���
void Test6()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(4);
	ListNode* pNode7 = CreateListNode(5);
	ListNode* pNode8 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);
	ConnectListNodes(pNode7, pNode8);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 2, 4 };
	Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// ������ֻ���������ظ��Ľ��
void Test7()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);

	ConnectListNodes(pNode1, pNode2);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 1, 2 };
	Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// �����ֻ��һ�����
void Test8()
{
	ListNode* pNode1 = CreateListNode(1);

	ConnectListNodes(pNode1, nullptr);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 1 };
	Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// �����ֻ�������ظ��Ľ��
void Test9()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);

	ConnectListNodes(pNode1, pNode2);

	ListNode* pHead = pNode1;

	Test("Test9", &pHead, nullptr, 0);

	DestroyList(pHead);
}

// ������
void Test10()
{
	ListNode* pHead = nullptr;

	Test("Test10", &pHead, nullptr, 0);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();

	return 0;
}