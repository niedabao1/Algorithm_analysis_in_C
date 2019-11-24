#pragma once
#include"stdafx.h"
typedef unsigned int Index;




Index Hash(const char *key, int TableSize)//使用Horner算法进行散列
{
	unsigned int hashVal = 0;

	while (*key != '\0')
		hashVal = (hashVal << 5) + *key++;

	return hashVal % TableSize;

}