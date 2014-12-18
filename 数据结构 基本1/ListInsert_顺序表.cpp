#include <stdio.h> 
#include <malloc.h>

#define	MAXSIZE	100

typedef int ElementType;	

typedef  struct
{ 
	ElementType  Data[MAXSIZE];   
  int  Last;											// List L; 线性表的长度：L.Last+1 或 PtrL->Last+1
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
        PtrL->Data[i-1] = X;   /*新元素插入*/
        PtrL->Last++;              /*Last仍指向最后元素*/
        return; 
} 


int	main()
{
	int	A[8] = {1,2,3,4,5,100,200,300};
	int	i, j, e = 586;
	List	*L;
	
	L = MakeEmpty();
	
	for(i=1, j=0; i<=8; i++, j++)
		Insert( A[j], i, L );
				
	printf("\n插入之前的元素序列为：\n");
	for(i=1; i<= L->Last+1; i++)
		printf("%d ", L->Data[i-1]);	
			
	i = 3;   //插入位置 
	Insert( e, i, L );;
	
	printf("\n\n插入后的元素序列为：\n");
	for(i=1; i<= L->Last+1; i++)
		printf("%d ", L->Data[i-1]);	
			
	printf("\n\n");
}
