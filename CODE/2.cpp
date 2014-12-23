#include <cstdio>
int check(int a[],int b[],int n){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}

int main() {
	int n,a[101],b[101],c[101],d[101],flag=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[i]=a[i];
		d[i]=a[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<n;i++){
		int index=i;
		for(int j=i;j>=0;j--){
			if(c[i]<c[j])index=j;
		}
		if(index!=i){
			int t=c[i];
			for(int j=i;j>index;j--){
				c[j]=c[j-1];
			}
			c[index]=t;
		}
		if(flag){
			for(int j=0;j<n;j++){
				printf("%d",c[j]);
				if(j!=n-1)putchar(' ');
			}
			return 0;
		}
		if(check(b,c,n)){
			printf("Insertion Sort\n");
			flag=1;
		}
	}
	return 0;
}
