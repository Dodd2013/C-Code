#include <cstdio>
int main() {
	int n,j=1,a=1;
	scanf("%d",&n);
	for(int i=1;i<=(1+n)*n/2;i++){
		printf("%d ",i);
		if(i==j){
			printf("\n");
			a++;
			j=j+a;
		}
	}
	return 0;
}
/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
