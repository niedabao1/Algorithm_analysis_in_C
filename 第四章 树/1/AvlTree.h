#pragma once
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>

struct Avlnode;
typedef struct Avlnode* Position;
typedef struct Avlnode* AvlTree;


AvlTree MakeEmpty(AvlTree T);
static int Height(Position P);//返回节点高度
AvlTree Insert(int X, AvlTree T);//插入
static Position SingleRotateWithLeft(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
static Position SingleRotateWithRight(Position K2);

struct Avlnode
{
	Avlnode():key(NULL),Left(NULL),Right(NULL),Height(NULL){}
	int key;		//存储内容

	AvlTree Left;	//树的架构
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


//先递归进行数据插入,等到插入完毕后进行旋转让树平衡
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
		if (Height(T->Left) - Height(T->Right) == 2)//右节点为空
			if (X < T->Left->key)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithRight(T);

	}
	else if (X > T->key)
	{
		T->Right = Insert(X, T->Left);
		if (Height(T->Right) - Height(T->Left) == 2)//左节点
			if (X > T->Right->key)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithRight(T);
	}
	//Else x is in the tree already;we'll do nothing
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
}

static Position SingleRotateWithLeft(Position K2)//左单旋,如k2不是根,则需要添加K2父亲指向K1
{
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;
	return K1;
}



static Position DoubleRotateWithLeft(Position K3)//左双选为一次右单旋和一次左单旋
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

int Max(int x, int y)//这个是寻找最大高度,不能这样写.
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