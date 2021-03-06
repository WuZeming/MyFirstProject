// _18_delete_node_in_list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"../Utilities/List.h"


void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (pListHead ==nullptr || pToBeDeleted ==nullptr)
	{
		return;
	}
	//尾节点
	if (pToBeDeleted->m_pNext  == nullptr)
	{
		if (*pListHead == pToBeDeleted) //只有一个节点
		{
			*pListHead = nullptr;
		}
		else
		{
			ListNode* pCurr = *pListHead;
			while (pCurr->m_pNext != pToBeDeleted)
				pCurr = pCurr->m_pNext;
			pCurr->m_pNext = nullptr;
		}

	}
	else
	{
		ListNode* temp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
		pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
		pToBeDeleted = temp;
	}
	delete pToBeDeleted;
	pToBeDeleted = nullptr;

}


// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode)
{
	printf("The original list is: \n");
	PrintList(pListHead);

	printf("The node to be deleted is: \n");
	PrintListNode(pNode);

	DeleteNode(&pListHead, pNode);

	printf("The result list is: \n");
	PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode3);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode5);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode1);

	DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
	Test(nullptr, nullptr);
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