#include <cstdio>
#include <algorithm>
using namespace std;
int a[10000];
bool cmp(int a1,int b){
	int ai=0,bi=0,af[10],bf[10];
	for(;a1>0;ai++){
		af[ai]=a1%10;
		a1/=10;
	}
	for(;b>0;bi++){
		bf[bi]=b%10;
		b/=10;
	}
	for(;bi>0||ai>0;bi--,ai--){
		if(bf[bi-1]>af[ai-1])return true;
		else if(bf[bi-1]<af[ai-1])return false;
	}
	return false;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(!cmp(a[i],a[j])){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		printf("%d",a[i]);
	} 
}
