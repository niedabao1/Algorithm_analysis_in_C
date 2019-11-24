#pragma once
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>

struct Avlnode;
typedef struct Avlnode* Position;
typedef struct Avlnode* AvlTree;


AvlTree MakeEmpty(AvlTree T);
static int Height(Position P);//���ؽڵ�߶�
AvlTree Insert(int X, AvlTree T);//����
static Position SingleRotateWithLeft(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
static Position SingleRotateWithRight(Position K2);

struct Avlnode
{
	Avlnode():key(NULL),Left(NULL),Right(NULL),Height(NULL){}
	int key;		//�洢����

	AvlTree Left;	//���ļܹ�
	AvlTree Right; 
	int		Height;
};

static int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}


//�ȵݹ�������ݲ���,�ȵ�������Ϻ������ת����ƽ��
AvlTree Insert(int X, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof( AvlTree));
		if (T == NULL)
			printf("Out of space!!!");
		else
		{
			T->key = X; T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->key)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)//�ҽڵ�Ϊ��
			if (X < T->Left->key)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithRight(T);

	}
	else if (X > T->key)
	{
		T->Right = Insert(X, T->Left);
		if (Height(T->Right) - Height(T->Left) == 2)//��ڵ�
			if (X > T->Right->key)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithRight(T);
	}
	//Else x is in the tree already;we'll do nothing
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
}

static Position SingleRotateWithLeft(Position K2)//����,��k2���Ǹ�,����Ҫ���K2����ָ��K1
{
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;
	return K1;
}



static Position DoubleRotateWithLeft(Position K3)//��˫ѡΪһ���ҵ�����һ������
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

int Max(int x, int y)//�����Ѱ�����߶�,��������д.
{
	if (x < y)
		return y;
	else if (x > y)
		return x;
	else
		return NULL;
}


int Height(Position T)
{
	if (T == NULL)
		return -1;
	else
		return 1 + Max(Height(T->Left), Height(T->Right));
}