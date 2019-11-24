#pragma once
#include<iostream>
typedef unsigned int Index;
typedef Index Position;
const int MinTableSize = 1;

struct HashTbl;
typedef struct HashTbl *HashTable;

int NextPrime(int X);
HashTable InitializeTable(int TableSize);


enum KindOfEntry {Legitimate,Empty,Deleted};

struct HashEntry
{
	int  Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct  HashTbl
{
	int TableSize;
	Cell *TheCells;
};

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if (TableSize < MinTableSize)
	{
		std::cerr << "´íÎó";
		return NULL;
	}

	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		std::cerr << "Out of space";

	H->TableSize = NextPrime(TableSize);

	H->TheCells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
	if (H->TheCells == NULL)
		std::cerr << "Out of space";

	for (i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;
	return H;
}


int NextPrime(int X)
{
	return X % 10;
}
