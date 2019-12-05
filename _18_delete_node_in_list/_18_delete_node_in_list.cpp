// _18_delete_node_in_list.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"../Utilities/List.h"


void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (pListHead ==nullptr || pToBeDeleted ==nullptr)
	{
		return;
	}
	//β�ڵ�
	if (pToBeDeleted->m_pNext  == nullptr)
	{
		if (*pListHead == pToBeDeleted) //ֻ��һ���ڵ�
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


// ====================���Դ���====================
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

// �������ж����㣬ɾ���м�Ľ��
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

// �������ж����㣬ɾ��β���
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

// �������ж����㣬ɾ��ͷ���
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

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1, pNode1);
}

// ����Ϊ��
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