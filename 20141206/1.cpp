#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n,m,i,an,bn,j;
	char ch;
	int a[1000],b[1000];
	scanf("%d%d",&n,&m);
	for(i=0,j=0;j<n;i++){
		scanf("%d%c",&a[i],&ch);
		if(ch=='\n')j++;
	}
	an=i;
	for(i=0,j=0;j<m;i++){
		scanf("%d%c",&b[i],&ch);
		if(ch=='\n')j++;
	}
	bn=i;
	sort(a,a+an);
	sort(b,b+bn);
	for(i=0,j=0;i<an||j<bn;){
		if(a[i]<b[j])printf("%d ",a[i++]);
		if(a[i]==b[j]){i++,j++;}
		if(a[i]>b[j])printf("%d ",b[j++]);
	}
	return 0;
}
