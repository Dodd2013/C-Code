#include <cstdio>
int main(){
	int m;
	scanf("%d",&m);
	for(int i=1;i<10;i++){
	for(int j=0;j<10;j++){
		int t=m-(i+j)*2;
		if(t<10&&t>=0){
			printf("%d%d%d%d%d\n",i,j,t,j,i);
		}
	}
}
	if(m%2==0){
		for(int i=1;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				if(i+j+k==m/2)printf("%d%d%d%d%d%d\n",i,j,k,k,j,i);
			}
		}
	}	
	}
	return 0;
}
