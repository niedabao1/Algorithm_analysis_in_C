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
/*为空返回0*/
int IsEmpty(List L)
{
	
	return L->Next == nullptr;
	
}
//是否为链表末尾
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
//查找某项
Position Find(ElementType x, List L)
{
	Position P;

	P = L->Next;
	while (P != NULL && P->Element != x)
		P = P->Next;

	return P;
}


//与Delete连用
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while (P->Next != NULL && P->Next->Element != X)	//查找对应成员第一次出现处
	{
		P = P->Next;
	}
	return P;
}
//删除(delete)表L中的X元素
void Delete(ElementType X, List L)
{
	Position P, Tmpcell;

	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		Tmpcell = P->Next;
		P->Next = Tmpcell->Next;//建立新链接(被删成员两边)
		free(Tmpcell);
	}
		
}

//插入(insert)成员到位置P后
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = Position(malloc(sizeof(struct Node)));	//为什么空间分配失败?
	if (TmpCell == NULL)
	{
		printf("Out of space!!!");

	}
	TmpCell->Element = X;//成员内容
	TmpCell->Next = P->Next;//指向链表中下一项
	P->Next = TmpCell;//上一项指向它
}


