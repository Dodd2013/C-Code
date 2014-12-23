#include <cstdio>
#include <cmath>
int main() {
	long long aa,bb,cc;
	int a,b,c,ans=0;
	scanf("%d",&c);
	cc=c*c;
	for(a=1;a<c/sqrt(2);a++){
		aa=a*a;
		b=sqrt(cc-aa);
		if(b*b+aa==cc)ans++;
	}
	printf("%d",ans);
	return 0;
}
