#include"linked_list.h"
 int main()
 {
     List L = CreateList(0);
     for(int i = 11;i > 0;i--)
     {
        Insert(i,L);
     }
     PrintList(L);
 }