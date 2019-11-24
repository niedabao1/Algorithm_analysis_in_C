#include<stdio.h>
#include<stdlib.h>



struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList(int num);//创建节点
 int IsEmpty(List L);//创建列表时需要人为将最末向的 Node.next 值设置为空
 int IsLast(Position P,List L);//p是当前位置
 Position Find(int Num ,List L1);//寻找指定位置
 void Insert(int InsertNum ,Position P );//在指定位置插入数字
Position FindPrevious(int Num,List L);//供函数使用的寻找特定值函数
void Delete(int x ,List L);//删除指定数值的元素 .如有多个元素,则删除第一个.
void Kill(List L);//删除整个链表
void PrintList(List L);//打印链表


struct Node
{
    int Num;
  //  char Name[5];
    Position Next;
};

List CreateList(int X)
{
  List node = (List)malloc(sizeof(struct Node));
  List end = (List)malloc(sizeof(struct Node));
  node->Num = X;
  node->Next = end;
  end->Next =NULL;
 return node;
}

int IsEmpty(List L)
{
   return L->Next == NULL;
}

int IsLast(Position P,List L)//p是当前位置
{
    return P->Next == NULL;
}

 Position Find(int CompareNum ,List L1)
 {
   Position L = L1;
   if(L->Next == NULL)  //把第一次验证提取出来以提高效率
   {
     if(L->Num == CompareNum)
     {
       return L;
     }
     else
     return NULL;
   }

   do
   {
     if(L->Num == CompareNum)
     {
       return L;
     }
     else
     {
       L = L->Next;
     }
   }while(L->Next  == NULL);
   return NULL;
 }

 void Insert(int InsertNum,Position P )//插入到选定位置后面
 {
   Position P1  = (Position)malloc(sizeof(struct Node));//申请空间
   P1->Num = InsertNum;
   P1->Next = P->Next;
   P->Next = P1;
 }

Position FindPrevious(int Num,List L)
{
  Position P = L;
  while (P->Next != NULL && P->Next->Num != Num)//书上有个小问题,链表尾值与NUM相同与链表中无此值返回结果相同.
  {
    P->Next;
  }
  return P;
}

void Delete(int x ,List L)
{
  Position P,TmpCell;
  P = FindPrevious(x,L);
  if(!IsLast(P,L))
  {
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
  }
}

void Kill(List L)
{
  if(L->Next != NULL)
    Kill(L->Next);
  free(L);
}

void PrintList(List L)
{
  
  while(L->Next != NULL)
  {
    if(L->Next->Next != NULL)
    {
      printf("%d->",L->Num);
      L=L->Next;
    }
    else
    {
      printf("%d",L->Num);
      L=L->Next;
    }
  }
   printf("\n");
}