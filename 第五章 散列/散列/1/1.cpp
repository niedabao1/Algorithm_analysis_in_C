// 1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef unsigned int Index;

Index Hash(const char *key, int TableSize)
{
	unsigned int Hashval = 0;

	while (*key != '\0')
	{
		Hashval += *key++;

	}
	return Hashval % TableSize;
}
int main()
{
	
    return 0;
}

