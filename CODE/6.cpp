#include <cstdio>
#define MAXN 4
void fun(long long a[][MAXN],long long b[][MAXN],int an,int am,int bn,int bm){
	long long c[MAXN][MAXN],t;
	if(am!=bn)return;
	for(int i=0;i<an;i++){
		for(int j=0;j<bm;j++){
			t=0;
			for(int k=0;k<am;k++){
				t+=a[i][k]*b[k][j]%10000;
			}
			c[i][j]=t;
		}
	}
	for(int i=0;i<an;i++){
		for(int j=0;j<bm;j++){
			a[i][j]=c[i][j];
		}
	}
}
void mi(long long a[][MAXN],int n){
	long long b[MAXN][MAXN];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			b[i][j]=a[i][j];
		}
	}
	while(n){
		if(n&1)
			fun(a,b,2,2,2,2);
		fun(b,b,2,2,2,2);
		n>>=1;
	}
}
int main(){
	int n;
	do{
		scanf("%d",&n);
		if(n==-1)break;
		if(n==0)printf("0\n");
		else if(n==1)printf("1\n");
		else{
			long long a[MAXN][MAXN]={{0,1}},
			b[MAXN][MAXN]={{0,1},{1,1}};
			mi(b,n-2);
			fun(a,b,1,2,2,2);
			printf("%d\n",a[0][1]);	
		}
		
	}while(1);
} 
