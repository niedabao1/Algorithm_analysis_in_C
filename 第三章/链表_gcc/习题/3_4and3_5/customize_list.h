//这个头文件用于自动生成各式的链表
#include"linked_list.h"
#include<stdlib.h>
#include<stdio.h>



List createListExampleOrdered(unsigned  StarNum,unsigned Length,unsigned  IntervalNum)//自动生成以StarNum为起始数,Length为长度,IntervalNum为间隔数的顺序排列链表
{
   List Ls = CreateList(StarNum);
   List FirstLS = Ls;
   for(int i = 1 ; i < Length ; i++)
   {
       StarNum += IntervalNum;
       Insert(StarNum,Ls);
       Ls = Ls->Next;//向前进一项
   }
   return FirstLS;
}