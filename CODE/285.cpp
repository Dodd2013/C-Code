#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,a[200];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]>a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
