#include"linked_list.h"

int NodeChange(List L,PtrToNode L1,PtrToNode L2)//调整指针来交换两个相邻
{
    while (L->Next != L1 || L->Next != L2 || L->Next == NULL)
    {
        L = L->Next;
    }
    if(L->Next == NULL)
    {
        return 1;
    }
     else  if(L->Next == L1)
    {
     
        L1->Next = L2->Next;
        L->Next = L2;
        L2->Next = L1;
        return 0;
    }
     else  if(L->Next == L2)
    {
     
        L2->Next = L1->Next;    
        L->Next = L1;
        L1->Next = L2;
        return 0;
    }
}

 int main()
 {
     List L = CreateList(0);
     for(int i = 11;i > 0;i--)
    {
        Insert(i,L);
    }
    
 }