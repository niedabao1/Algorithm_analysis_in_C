#include<stdio.h>
#include"linked_list.h"




int main(int argc,char** argv)
{
 List L = CreateList(1);
 Insert(5,L,L);
 PrintList(L);
 Kill(L);
}