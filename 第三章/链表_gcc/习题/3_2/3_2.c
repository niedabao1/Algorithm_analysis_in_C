#include "linked_list.h"

void PrintLots(List L,List P);
int main()
{
List L = CreateList(0);
     for(int i = 100;i > 0;i--)
     {
        Insert(i,L);
     }
     PrintList(L);//向上为题目部分:包含以升序排列的元素

List P = CreateList(0);
 for(int i = 100;i > 0;i=i-3)
     {
        Insert(i,P);
     }
     PrintList(P);//向上为题目部分:包含以升序排列的元素

PrintLots(L,P);
}

void PrintLots(List L,List P)//
{
    int x_back = 0;
    while(P->Next != NULL)
    {
    
    int x_next = P->Num;
        for(int i = x_back;i < x_next;i++)
        {
            L = L->Next;
        }
    printf("%d ",L->Num);
    P = P->Next;
    x_back = x_next;
    }
}