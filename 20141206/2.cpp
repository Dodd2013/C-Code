#include <cstdio>
#include <algorithm>
using namespace std;
int check(int a[]){
	int x,y,z;
	x=a[0]*100+a[1]*10+a[2];
	y=a[3]*100+a[4]*10+a[5];
	z=a[6]*100+a[7]*10+a[8];
	if(y==2*x&&z==3*x)return 1;
	else return 0;
}
int main() {
	int a[]={1,2,3,4,5,6,7,8,9};
	do{
		if(check(a)){
			for(int i=0;i<9;i++){
				printf("%d",a[i]);
				if((i+1)%3==0)putchar(' ');
			}
			puts("");
		}
	}while(next_permutation(a,a+9));
	return 0;
}
