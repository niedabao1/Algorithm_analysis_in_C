#pragma once
#include"stdafx.h"
typedef unsigned int Index;




Index Hash(const char *key, int TableSize)//ʹ��Horner�㷨����ɢ��
{
	unsigned int hashVal = 0;

	while (*key != '\0')
		hashVal = (hashVal << 5) + *key++;

	return hashVal % TableSize;

}