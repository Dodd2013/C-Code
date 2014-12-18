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
		 List  *p = PtrL;       /* pָ���ĵ�һ�����*/
     ......
     while ( p != NULL [&&  ||  condition]) { 
           p = p->Next; 
           ......
     }   
     ......
}


// 1.���
int  Length ( List  *PtrL )
{    List  *p = PtrL;       /* pָ���ĵ�һ�����*/
     int  j = 0;
     while ( p != NULL ) { 
           p = p->Next; 
           j++;                    /* ��ǰpָ����ǵ� j �����*/
     }   
     return  j;
}


// 2.  ����

//��1������Ų���: FindKth;        
List  *FindKth( int K, List *PtrL )
{      List  *p = PtrL;
        int  i = 1;
        while (p !=NULL && i < K ) {
               p = p->Next;
               i++;  
        }
       if ( i == K ) 
       		return p;  
/* �ҵ���K��������ָ�� */
       else  return NULL;    
 /* ���򷵻ؿ� */
}

//��2����ֵ����: Find
List *Find( ElementType X, List *PtrL )
{  
    List  *p = PtrL;
    while ( p!=NULL && p->Data != X )
           p = p->Next;  
    return p;
}


//  �����㷨
List *Insert( ElementType X, int i, List *PtrL )
{       List  *p, *s;
        if ( i == 1 ) 
        { /* �½������ڱ�ͷ */
             s = (List *)malloc(sizeof(List)); /*���롢��װ���*/
             s->Data = X; 
             s->Next = PtrL;
             PtrL = s;
             return PtrL;      /*�����±�ͷָ��*/
        }
        
        p = FindKth( i-1, PtrL );   /* ���ҵ�i-1����� */
        
        if ( p == NULL ) 
        { /* ��i-1�������ڣ����ܲ��� */
                 printf(������i��);
                 return NULL; 
        }
        else 
        {
                s = (List *)malloc(sizeof(List)); /*���롢��װ���*/
                s->Data = X; 
                s->Next = p->Next;     /*�½������ڵ�i-1�����ĺ���*/
                p->Next = s; 
                return PtrL;
        }
}

//  ɾ���㷨
List *Delete( int  i, List *PtrL )
{       List  *p, *s;
        if ( i == 1 ) 
        {                 /* ��Ҫɾ�����Ǳ�ĵ�һ����� */
               s = PtrL;                /*sָ���1�����*/
               PtrL = PtrL->Next;     /*��������ɾ��*/
               free(s);                 /*�ͷű�ɾ����� */
               return PtrL;
        }
        
        p = FindKth( i-1, PtrL );      /*���ҵ�i-1�����*/
        
        if ( p == NULL ) 
        { 
                printf(����%d����㲻���ڡ�, i-1);     return NULL; 
        } 
        else  if ( p->Next == NULL ){ 
                printf(����%d����㲻���ڡ�, i);      return NULL; 
        } 
        else  
        {
               s = p->Next;             /*sָ���i�����*/
               p->Next = s->Next;      /*��������ɾ��*/
               free(s);                      /*�ͷű�ɾ����� */
               return PtrL;
        }
}


// 
/* [��2.4] ����һ��������L������ƺ���Reverse������L�͵���ת��������Ҫ�����µĽ�㣬������ĵ�һ��Ԫ��תΪ���һ��Ԫ�أ��ڶ���Ԫ��תΪ�����ڶ���Ԫ�أ�������   */

struct Node *Reverse(struct Node *L)
{   
	struct Node *p, *q, *t;
  p = L��q = NULL;
  while ( p != NULL ) 
  {
         t = p->Next;
         p->Next = q;  
         q = p;
         p = t;
  }
  return q;
}

