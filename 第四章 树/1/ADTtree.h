#pragma once
#include"stdafx.h"
#include<stdlib.h>
#ifndef ADTtree
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
SearchTree MakeEmpty(SearchTree T);

#endif // !ADTtree

struct TreeNode
{
	int key ;
	SearchTree  Left;
	SearchTree Right;
	TreeNode():key(0),Left(NULL),Right(NULL){}
	
};

SearchTree MakeEmpty(SearchTree T)//�ͷ���
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(int X, SearchTree T)//��������Ԫ��
{
	if (T == NULL)
		return NULL;
	if (X < T->key)
		return Find(X, T->Left);
	else if (X > T->key)
		return Find(X, T->Right);
	else
		return T;
}


SearchTree Insert(int X, SearchTree T)//���ݲ���������
{
	if (T == NULL)
	{
		T = (TreeNode*)malloc(sizeof(struct TreeNode));
		if (T == NULL)
			return NULL;
		else
		{
			T->key = X;
			T->Left = T->Right = NULL;
		}
	}
	else
	{
		if (X < T->key)
			T->Left = Insert(X, T->Left);//����:δ�����಻��NULL

		else if(X > T->key)
			T->Right = Insert(X, T->Right);//if tree has same value,do nothing;

	}
	return T;
}

Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

SearchTree Delete(int X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
		printf("Not found");
	else if (X < T->key)	//����
		T->Left = Delete(X, T->Left);
	else if (X > T->key)	//����
		T->Right = Delete(X, T->Right);

	else if (T->Left && T->Right)//����������
	{
		TmpCell = FindMin(T->Right);//�Ҳ���������Сkey
		T->key = TmpCell->key;
		T->Right = Delete(T->key, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}

void PrintTree(SearchTree T)//�������
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		printf("%d", T->key);
		PrintTree(T->Right);
	}
	
}


