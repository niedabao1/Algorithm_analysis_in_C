#include<stdlib.h>
#include<stdio.h>

struct TwoNode;
typedef struct TwoNode *TwoPtrToNode;
typedef TwoPtrToNode TwoList;
typedef TwoPtrToNode TwoPosition;

TwoList CreateList(int x);
int InsertNext(int x,TwoList L);//在指定位置的前方插入
void DeleteList(TwoList L);

struct TwoNode
{
    int Num;
  //  char Name[5];
    TwoPosition Next;
    TwoPosition Back;
};

TwoList CreateList(int x)
{
    TwoList L;
    L= (TwoList)malloc(sizeof(struct TwoNode));
    L->Num = x;
    L->Next = L->Back = NULL;
    return 0;
}

int InsertNext(int x,TwoList L)//在指定位置的前方插入
{
    while(L->Next != NULL )
    {
        if(L->Num = x)
        {
            if(L->Back != NULL)
            {
            TwoList addNode = (TwoList)malloc(sizeof(struct TwoNode));
            addNode->Next = L;
            addNode->Back = L->Back;
            L->Back->Next = addNode;
            L->Back  = addNode;
            }
            else
            {
            TwoList addNode = (TwoList)malloc(sizeof(struct TwoNode));
            addNode->Next = L;
            addNode->Back = NULL;
            L->Back  = addNode;             
            }
        }
        L = L->Next;
        
    }   
}

void DeleteList(TwoList L)
{
    TwoList l;
    while (L->Next != NULL)
    {
      l = L->Next ;
      free(L);
      L = l;
    }
    
}