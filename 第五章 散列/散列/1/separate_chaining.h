#pragma once
//分离链接法
#include<iostream>	
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include"Hsah.h"

struct ListNode;
typedef struct ListNode* Position;
struct HashTb1;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
int NextPrime(int X);
Position Find(char key[10], HashTable H);


struct ListNode
{
	char Element[10];//key
	Position Next;//指向下一节点的指针
};

typedef Position List;

struct HashTbl
{
	int TableSize;//表的大小
	List *TheLists;//使用指针的指针是为了建立ListNode指针的数组
};

HashTable InitializeTable(int TableSize)//初始化函数
{
	HashTable H;
	int i;

	if (TableSize < 1)
	{
		std::cerr << "Table size too small";
		return NULL;
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		std::cerr << "Out of space";

	H->TableSize = NextPrime(TableSize);  //将表的大小打乱并尽量使大小为素数   实例并未用素数

	H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);
	if (H->TheLists == NULL)
		std::cerr << "Out of space";

	for (i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] = (ListNode*)malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
			std::cerr << "out of space";
		else
			H->TheLists[i]->Next = NULL;
	}
	return H;
}

int NextPrime(int X)
{
	return X % 10;
}

Position Find(char key[10], HashTable H)
{
	Position P;
	List L;

	L = H->TheLists[Hash(key, H->TableSize)];
	P = L->Next;
	while (P != NULL && !strcmp(P->Element,key))
		P = P->Next;
	return P;
}

void Insert(char key[10], HashTable H)
{
	Position Pos, NewCell;
	List L;

	Pos = Find(key, H);
	if (Pos == NULL)
	{
		NewCell = (ListNode*)malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
			std::cerr << ("Out of space");
		else
		{
			L = H->TheLists[Hash(key, H->TableSize)];
			NewCell->Next = L->Next;
			memcpy(key, NewCell->Element,10);
			L->Next = NewCell;
		}
	}
}