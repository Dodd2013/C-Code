#include <stdio.h>
#include <stdlib.h>
#define maxc(x,y) ((x)=(x)<(y)?(y):(x))
int buf[2001][2001];
int b[501];
int inl,ink,cutl,cutk;
int bn;
int back(const void * p1,const void * p2)
{
	return (*((int *)p1))-(*((int *)p2));
}
int fun(int l,int k)
{
	int i,j,bi;
	int max;
	if(l*k<cutl*cutk)return 0;
	if(l<cutk||k<cutk)return 0;
	if(k<cutl&&l<cutl)return 0;
	if(l==cutl&&k==cutk)return 1;
	if(l==cutk&&k==cutl)return 1;
	else
	{
		max=0;
		for(bi=1;bi<bn;bi++)
		{
			if(k-b[bi]>0)
			{
				maxc(max,(buf[l][k-b[bi]]?buf[l][k-b[bi]]:fun(l,k-b[bi]))+(buf[l][b[bi]]?buf[l][b[bi]]:fun(l,b[bi])));
			}
			if(l-b[bi]>0)
			{
				maxc(max,(buf[l-b[bi]][k]?buf[l-b[bi]][k]:fun(l-b[bi],k))+(buf[b[bi]][k]?buf[b[bi]][k]:fun(b[bi],k)));
			}
		}
		buf[l][k]=max;
		buf[k][l]=max;
		return max;
	}
	
}
int main(){
	int i,j;
	scanf("%d%d%d%d",&inl,&ink,&cutl,&cutk);
	if(inl<ink)inl^=ink^=inl^=ink;
	if(cutl<cutk)cutl^=cutk^=cutl^=cutk;
	for(i=1;i*cutl<inl;i++)
	{
		b[i]=i*cutl;
		
	}
		for(j=1;j*cutk<inl;i++,j++)
	{
		b[i]=j*cutk;
		
	}
	bn=i;
	qsort(b,bn,4,back);
	printf("%d",fun(inl,ink));
	return 0;
}
