#include <cstdio>
#include <algorithm>
using namespace std;
int fun(int a[],int n){
	for(int i=0;i<9;i++){
		for(int j=i;j<9;j++){
			int sum=0,sum1=0,sum2=0;
			for(int x=0;x<i;x++){
				sum*=10;
				sum+=a[x];
			}
			for(int y=i;y<j;y++){
				sum1*=10;
				sum1+=a[y];
			}
			for(int z=j;z<9;z++){
				sum2*=10;
				sum2+=a[z];
			}
			if(sum2!=0&&sum1%sum2==0&&(sum1/sum2)+sum==n)return 1;
		}
	}
	return 0;
}
int main() {
	int a[]={1,2,3,4,5,6,7,8,9};
	int n,ans=0;
	scanf("%d",&n);
	do{
		if(fun(a,n))ans++;
	}while(next_permutation(a,a+9));
	printf("%d",ans);
	return 0;
}
