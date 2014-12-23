#include <cstdio>
#define MAX 100
#define MAXN 9999999
int v[MAX],u[MAX][MAX];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int t1,t2,cost;
		scanf("%d%d%d",&t1,&t2,&cost);
		u[t1][t2]=cost;
		u[t2][t1]=cost;
	}
	for(int i=1;i<=n;i++){
		v[i]=MAXN;
	}
	v[1]=-1;
	for(int i=2;i<=n;i++){
		int min=MAXN;
		for(int j=1;j<=n;j++){
			if(v[i]){
				for(int k=1;k<=n;k++){
					
				}
			}
		}
	}
	return 0;
}
