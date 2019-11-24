#pragma once
#include "stdafx.h"
#include<malloc.h>
#include<stdlib.h>
#ifndef _list_H

struct Node;
typedef Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif // !_list_H
struct Node
{
	ElementType Element;
	Position Next;
};
/*Ϊ�շ���0*/
int IsEmpty(List L)
{
	
	return L->Next == nullptr;
	
}
//�Ƿ�Ϊ����ĩβ
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
//����ĳ��
Position Find(ElementType x, List L)
{
	Position P;

	P = L->Next;
	while (P != NULL && P->Element != x)
		P = P->Next;

	return P;
}


//��Delete����
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while (P->Next != NULL && P->Next->Element != X)	//���Ҷ�Ӧ��Ա��һ�γ��ִ�
	{
		P = P->Next;
	}
	return P;
}
//ɾ��(delete)��L�е�XԪ��
void Delete(ElementType X, List L)
{
	Position P, Tmpcell;

	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		Tmpcell = P->Next;
		P->Next = Tmpcell->Next;//����������(��ɾ��Ա����)
		free(Tmpcell);
	}
		
}

//����(insert)��Ա��λ��P��
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = Position(malloc(sizeof(struct Node)));	//Ϊʲô�ռ����ʧ��?
	if (TmpCell == NULL)
	{
		printf("Out of space!!!");

	}
	TmpCell->Element = X;//��Ա����
	TmpCell->Next = P->Next;//ָ����������һ��
	P->Next = TmpCell;//��һ��ָ����
}


