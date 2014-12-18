#include <stdio.h> 
#include <malloc.h>

#define	MAXSIZE	100
typedef int ElementType;	

typedef  struct
{ 
	ElementType  Data[MAXSIZE];   
  int  Last;									// last��ʾ���һ�����ݵ��±ꡣ���Ա�ĳ��ȣ�L.Last+1 �� PtrL->Last+1
} List; 


List *MakeEmpty( )
{    
		 List *PtrL;
     PtrL = (List *)malloc( sizeof(List) );
     PtrL->Last = -1; 
     return PtrL;
}

// �����㷨
void Insert( ElementType X, int i, List *PtrL )
{       
				int j;
        if ( PtrL->Last == MAXSIZE-1 ){  /* ��ռ����������ܲ���*/
                 printf("����"); 
                 return; 
        }  
        if ( i < 1 || i > PtrL->Last+2) { /*������λ�õĺϷ���*/
               printf("λ�ò��Ϸ�");
               return; 
        } 
        for ( j = PtrL->Last; j >= i-1; j-- )
               PtrL->Data[j+1] = PtrL->Data[j];  /*�� ai�� an��������ƶ�*/
        PtrL->Data[i-1] = X;   			/*��Ԫ�ز���*/
        PtrL->Last++;              /*Last��ָ�����Ԫ��*/
        return; 
} 


void ClearList(List *L)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�

   L->Last = -1;

   return;

}

//==================
/*
�����Ա�����˳���A�У�������n��Ԫ�أ��ҵ������������һ�㷨����Ԫ��S���뵽���Ա���ʵ�λ�ã��Ա������Ա�������ԣ����Ҹ������㷨��ʱ�临�Ӷȡ�            */

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
				
	printf("\n����֮ǰ��Ԫ������Ϊ��\n");
	for(i=1; i<= L->Last+1; i++)
		printf("%d ", L->Data[i-1]);	
			
	Sq_Insert(L, e);
	
	printf("\n\n������Ԫ������Ϊ��\n");
	for(i=1; i<= L->Last+1; i++)
		printf("%d ", L->Data[i-1]);	
			
	printf("\n\n");
}
