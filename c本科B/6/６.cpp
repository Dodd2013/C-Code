#include <cstdio>
#include <string.h>
int a[9][9],row[9][10],col[9][10],g[10][10];
void fun(int x,int y){
	if(x==9&&y==0){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				printf("%d ",a[i][j]);
			}
			puts("");
		}
	}
	
	if(a[x][y]!=0){
		if(y==8){
		fun(x+1,0);
		}
		else
		fun(x,y+1);
	}else
	for(int i=1;i<=9;i++){
		if(row[x][i]==1||col[y][i]==1||g[(x)/3*3+(y)/3][i]==1)
		continue;
		a[x][y]=i;
		row[x][i]=1;
		col[y][i]=1;
		g[(x)/3*3+(y)/3][i]=1;
		if(y==8)
			fun(x+1,0);
		else
			fun(x,y+1);
		row[x][i]=0;
		col[y][i]=0;
		g[(x)/3*3+(y)/3][i]=0;
		a[x][y]=0;
	}
} 
int main() {
	int n;
	scanf("%d",&n);
		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			scanf("%1d",&a[i][j]);
			if(a[i][j]!=0){
				row[i][a[i][j]]=1;
				col[j][a[i][j]]=1;
				g[(i)/3*3+(j)/3][a[i][j]]=1;
			}
		}
	}
	fun(0,0);
	return 0;
}
