// _07_rebuild_binary_tree.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<iostream>
#include<exception>
#include "stdafx.h"
#include "../Utilities/BinaryTree.h"

BinaryTreeNode* constructCore(int* startPreorder,int* endPreorder, int* startInorder, int* endInorder)
{
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = startPreorder[0];
	root->m_pLeft = root->m_pRight = nullptr;
	// �ж��Ƿ�ΪҶ�ڵ㣬Ҷ�ڵ���ֹ�ݹ�
	if (startPreorder == endPreorder && startInorder==endInorder)
	{
		if (*startPreorder == *startInorder)
		{
			return root;
		}
		else
		{
			throw std::exception("Invalid Input");
		}
	}
	// �ҵ����ڵ���������������е�λ��
	int * inroot = startInorder;
	while (inroot<=endInorder && *inroot!=*startPreorder)
	{
		++inroot;
	}
	if (inroot == endInorder && *inroot != *startPreorder)
	{
		throw std::exception("Invalid Input");
	}
	int leftlen = inroot - startInorder;
	int rightlen = endInorder - inroot;

	// �ֱ�ݹ齨����������
	if (leftlen>0)
	{
		root->m_pLeft = constructCore(startPreorder+1,startPreorder+leftlen,startInorder,inroot-1);
	    
	}
	if (rightlen>0)
	{
		root->m_pRight = constructCore(startPreorder+leftlen+1, endPreorder,inroot+1,endInorder);
	}

	return root;

}


BinaryTreeNode* construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length<=0)
	{
		return nullptr;
	}
	return constructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}



// ====================���Դ���====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		BinaryTreeNode* root = construct(preorder, inorder, length);
		PrintTree(root);

		DestroyTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// ��ͨ������
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("Test1", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	Test("Test2", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	Test("Test3", preorder, inorder, length);
}

// ����ֻ��һ�����
void Test4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	Test("Test4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	Test("Test5", preorder, inorder, length);
}

// �����ָ��
void Test6()
{
	Test("Test6", nullptr, nullptr, 0);
}

// ������������в�ƥ��
void Test7()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder, length);
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
	getchar();
	return 0;
}


