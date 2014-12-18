#include <stdio.h> 
#include <malloc.h>

#define	MAXSIZE	100

typedef int ElementType;	

typedef  struct
{ 
	ElementType  Data[MAXSIZE];   
  int  Last;											// List L; ���Ա�ĳ��ȣ�L.Last+1 �� PtrL->Last+1
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
        PtrL->Data[i-1] = X;   /*��Ԫ�ز���*/
        PtrL->Last++;              /*Last��ָ�����Ԫ��*/
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
				
	printf("\n����֮ǰ��Ԫ������Ϊ��\n");
	for(i=1; i<= L->Last+1; i++)
		printf("%d ", L->Data[i-1]);	
			
	i = 3;   //����λ�� 
	Insert( e, i, L );;
	
	printf("\n\n������Ԫ������Ϊ��\n");
	for(i=1; i<= L->Last+1; i++)
		printf("%d ", L->Data[i-1]);	
			
	printf("\n\n");
}
