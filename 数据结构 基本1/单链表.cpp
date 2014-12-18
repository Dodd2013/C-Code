typedef int ElementType;	

typedef  struct Node
{ 
     ElementType  Data;   
     struct Node *Next;
} List; 

List L, *PtrL;
struct Node *t;

t = Insert( X, i, PtrL );
p = (struct Node *) malloc(sizeof(struct Node));


...  fun ( ... )
{    
		 List  *p = PtrL;       /* p指向表的第一个结点*/
     ......
     while ( p != NULL [&&  ||  condition]) { 
           p = p->Next; 
           ......
     }   
     ......
}


// 1.求表长
int  Length ( List  *PtrL )
{    List  *p = PtrL;       /* p指向表的第一个结点*/
     int  j = 0;
     while ( p != NULL ) { 
           p = p->Next; 
           j++;                    /* 当前p指向的是第 j 个结点*/
     }   
     return  j;
}


// 2.  查找

//（1）按序号查找: FindKth;        
List  *FindKth( int K, List *PtrL )
{      List  *p = PtrL;
        int  i = 1;
        while (p !=NULL && i < K ) {
               p = p->Next;
               i++;  
        }
       if ( i == K ) 
       		return p;  
/* 找到第K个，返回指针 */
       else  return NULL;    
 /* 否则返回空 */
}

//（2）按值查找: Find
List *Find( ElementType X, List *PtrL )
{  
    List  *p = PtrL;
    while ( p!=NULL && p->Data != X )
           p = p->Next;  
    return p;
}


//  插入算法
List *Insert( ElementType X, int i, List *PtrL )
{       List  *p, *s;
        if ( i == 1 ) 
        { /* 新结点插入在表头 */
             s = (List *)malloc(sizeof(List)); /*申请、填装结点*/
             s->Data = X; 
             s->Next = PtrL;
             PtrL = s;
             return PtrL;      /*返回新表头指针*/
        }
        
        p = FindKth( i-1, PtrL );   /* 查找第i-1个结点 */
        
        if ( p == NULL ) 
        { /* 第i-1个不存在，不能插入 */
                 printf(＂参数i错＂);
                 return NULL; 
        }
        else 
        {
                s = (List *)malloc(sizeof(List)); /*申请、填装结点*/
                s->Data = X; 
                s->Next = p->Next;     /*新结点插入在第i-1个结点的后面*/
                p->Next = s; 
                return PtrL;
        }
}

//  删除算法
List *Delete( int  i, List *PtrL )
{       List  *p, *s;
        if ( i == 1 ) 
        {                 /* 若要删除的是表的第一个结点 */
               s = PtrL;                /*s指向第1个结点*/
               PtrL = PtrL->Next;     /*从链表中删除*/
               free(s);                 /*释放被删除结点 */
               return PtrL;
        }
        
        p = FindKth( i-1, PtrL );      /*查找第i-1个结点*/
        
        if ( p == NULL ) 
        { 
                printf(“第%d个结点不存在”, i-1);     return NULL; 
        } 
        else  if ( p->Next == NULL ){ 
                printf(“第%d个结点不存在”, i);      return NULL; 
        } 
        else  
        {
               s = p->Next;             /*s指向第i个结点*/
               p->Next = s->Next;      /*从链表中删除*/
               free(s);                      /*释放被删除结点 */
               return PtrL;
        }
}


// 
/* [例2.4] 给定一个单链表L，请设计函数Reverse将链表L就地逆转，即不需要申请新的结点，将链表的第一个元素转为最后一个元素，第二个元素转为倒数第二个元素，……。   */

struct Node *Reverse(struct Node *L)
{   
	struct Node *p, *q, *t;
  p = L，q = NULL;
  while ( p != NULL ) 
  {
         t = p->Next;
         p->Next = q;  
         q = p;
         p = t;
  }
  return q;
}

