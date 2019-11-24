#pragma once
//�������ӷ�
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
	Position Next;//ָ����һ�ڵ��ָ��
};

typedef Position List;

struct HashTbl
{
	int TableSize;//��Ĵ�С
	List *TheLists;//ʹ��ָ���ָ����Ϊ�˽���ListNodeָ�������
};

HashTable InitializeTable(int TableSize)//��ʼ������
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

	H->TableSize = NextPrime(TableSize);  //����Ĵ�С���Ҳ�����ʹ��СΪ����   ʵ����δ������

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