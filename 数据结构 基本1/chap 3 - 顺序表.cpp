#include <stdio.h> 
#include <malloc.h>

#define	MAXSIZE	100
typedef int ElementType;	

typedef  struct
{ 
	ElementType  Data[MAXSIZE];   
  int  Last;									// last表示最后一个数据的下标。线性表的长度：L.Last+1 或 PtrL->Last+1
} List; 


List *MakeEmpty( )
{    
		 List *PtrL;
     PtrL = (List *)malloc( sizeof(List) );
     PtrL->Last = -1; 
     return PtrL;
}

// 插入算法
void Insert( ElementType X, int i, List *PtrL )
{       
				int j;
        if ( PtrL->Last == MAXSIZE-1 ){  /* 表空间已满，不能插入*/
                 printf("表满"); 
                 return; 
        }  
        if ( i < 1 || i > PtrL->Last+2) { /*检查插入位置的合法性*/
               printf("位置不合法");
               return; 
        } 
        for ( j = PtrL->Last; j >= i-1; j-- )
               PtrL->Data[j+1] = PtrL->Data[j];  /*将 ai～ an倒序向后移动*/
        PtrL->Data[i-1] = X;   			/*新元素插入*/
        PtrL->Last++;              /*Last仍指向最后元素*/
        return; 
} 


void ClearList(List *L)
{ // 初始条件：顺序线性表L已存在。操作结果：将L重置为空表

   L->Last = -1;

   return;

}

//==================
/*
设线性表存放于顺序表A中，其中有n个元素，且递增有序，请设计一算法，将元素S插入到线性表的适当位置，以保持线性表的有序性，并且给出该算法的时间复杂度。            */

void Sq_Insert(List *L, ElementType	s)
{
 int i=0, j;
 while(s > L->Data[i])  
 		i++;
 for(j=L->Last; j>=i; j--)
  	L->Data[j+1] = L->Data[j];
 L->Data[i] = s;
 L->Last++; 
}


int	main()
{
	int	A[8] = {1,3,5,7,9,19,29,39};
	int	i, j, e = 10;
	List	*L;
	
	L = MakeEmpty();
	
	for(i=1, j=0; i<=8; i++, j++)
		Insert( A[j], i, L );
				
	printf("\n插入之前的元素序列为：\n");
	for(i=1; i<= L->Last+1; i++)
		printf("%d ", L->Data[i-1]);	
			
	Sq_Insert(L, e);
	
	printf("\n\n插入后的元素序列为：\n");
	for(i=1; i<= L->Last+1; i++)
		printf("%d ", L->Data[i-1]);	
			
	printf("\n\n");
}
