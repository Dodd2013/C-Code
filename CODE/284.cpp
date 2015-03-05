#include <cstdio>
int a[99999]={1};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=i;j>0;j--){
			a[j]=a[j]+a[j-1];
		}
		for(int j=0;j<=i;j++){
			printf("%d ",a[j]);
		}
		puts("");
	}
}
