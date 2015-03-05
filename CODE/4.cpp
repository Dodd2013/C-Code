#include <cstdio> 
int main(){int m[55]={1,1,2,3},n,i;for(i=4;i<55;i++)m[i]=m[i-1]+m[i-3];while(scanf("%d",&n),n)printf("%d\n",m[n]);}
