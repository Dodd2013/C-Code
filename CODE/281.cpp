#include <cstdio>
int a[5];
int f(int n){
	if(n>=5){
		for(int i=0;i<5;i++){
			printf("%d",a[i]);
		}
		puts("");
	}else{
		a[n]=1;
		f(n+1);
		a[n]=0;
		f(n+1);
	}
}
int main(){
	f(0);
}
