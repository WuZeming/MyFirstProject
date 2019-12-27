// _35_ComplexListClone.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ComplexList.h"

void CloneNodes(ComplexListNode*pHead);
void ConnectSibling(ComplexListNode* pHead);
ComplexListNode* ReconnectNode(ComplexListNode* pHead);


ComplexListNode* Clone(ComplexListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}
	CloneNodes(pHead);
	ConnectSibling(pHead);
	return ReconnectNode(pHead);
}

void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;

	while (pNode!= nullptr)
	{
		ComplexListNode* newNode = CreateNode(pNode->m_nValue);
		newNode->m_pNext = pNode->m_pNext;
		pNode->m_pNext = newNode;
		pNode = newNode->m_pNext;
	}
}

void ConnectSibling(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode!= nullptr)
	{
		if (pNode->m_pSibling != nullptr)
		{
			pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pNode->m_pNext->m_pNext;
	}
}

ComplexListNode* ReconnectNode(ComplexListNode* pHead)
{
	ComplexListNode* newHead = pHead->m_pNext;
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClone = newHead;
	while (pClone->m_pNext!= nullptr)
	{
		pNode->m_pNext = pClone->m_pNext;
		pNode = pNode->m_pNext;
		pClone->m_pNext = pNode->m_pNext;
		pClone = pClone->m_pNext;
	}
	pNode->m_pNext = nullptr;

	return newHead;
}







// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The original list is:\n");
	PrintList(pHead);

	ComplexListNode* pClonedHead = Clone(pHead);

	printf("The cloned list is:\n");
	PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, nullptr);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, pNode3);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, nullptr);
	BuildNodes(pNode2, pNode3, pNode4);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
	ComplexListNode* pNode1 = CreateNode(1);
	BuildNodes(pNode1, nullptr, pNode1);

	Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
	Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}