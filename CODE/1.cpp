#include <cstdio>
int gcd(int a,int b){
	int t;
	while(b!=0){
		t=a%b;
		if(t==0)return b;
		a=b%t;
		if(a==0)return t;
		b=t%a;
	}
	return a;
}
void f(int *a,int *b){
	if(*a==0||*b==0)return;
	int t=gcd(*a,*b);
	*a/=t;
	*b/=t;
}
int main() {
	char op[5]="+-*/";
	int a,b,c,d,ab=0,cd=0,fa=1,fb=1;
	int ansa1,ansb1,ansf1=1,ansab1=0;
	int ansa2,ansb2,ansf2=1,ansab2=0;
	int ansa3,ansb3,ansf3=1,ansab3=0;
	int ansa4,ansb4,ansf4=1,ansab4=0;
	scanf("%d/%d %d/%d",&a,&b,&c,&d);
	if(a<0)fa=-fa,a=-a;
	if(b<0)fa=-fa,b=-b;
	if(c<0)fb=-fb,c=-c;
	if(d<0)fb=-fb,d=-d;
	f(&a,&b);
	f(&c,&d);
	ansa1=fb*c*b+fa*a*d;
	ansb1=b*d;
	ansa2=-fb*c*b+fa*a*d;
	ansb2=ansb1;
	ansa3=a*c*fa*fb;
	ansb3=b*d;
	ansa4=a*d*fa*fb;
	ansb4=c*b;
	f(&ansa3,&ansb3);
	f(&ansa1,&ansb1);
	f(&ansa2,&ansb2);
	f(&ansa3,&ansb3);
	f(&ansa4,&ansb4);
	if(a-b>=0&&b!=0)ab=a/b,a=a%b;
	if(c-d>=0&&d!=0)cd=c/d,c=c%d;
	if(ansa1<0)ansf1=-ansf1,ansa1=-ansa1;
	if(ansb1<0)ansf1=-ansf1,ansb1=-ansb1;
	if(ansa1>=ansb1&&ansb1!=0)ansab1=ansa1/ansb1,ansa1%=ansb1;
	if(ansa2<0)ansf2=-ansf2,ansa2=-ansa2;
	if(ansb2<0)ansf2=-ansf2,ansb2=-ansb2;
	if(ansa2>=ansb2&&ansb2!=0)ansab2=ansa2/ansb2,ansa2%=ansb2;
	if(ansa3<0)ansf3=-ansf3,ansa3=-ansa3;
	if(ansb3<0)ansf3=-ansf3,ansb3=-ansb3;
	if(ansa3>=ansb3&&ansb3!=0)ansab3=ansa3/ansb3,ansa3%=ansb3;
	if(ansa4<0)ansf4=-ansf4,ansa4=-ansa4;
	if(ansb4<0)ansf4=-ansf4,ansb4=-ansb4;
	if(ansa4>=ansb4&&ansb4!=0)ansab4=ansa4/ansb4,ansa4%=ansb4;
	for(int i=0;i<4;i++){
		if(fa<0)putchar('(');
		if(ab!=0){
		printf("%d",fa*ab);
		if(a!=0)putchar(' ');
		}
		if(ab==0&&fa<0)putchar('-');
		if(a!=0)printf("%d/%d",a,b);
		if(ab==0&&a==0)printf("0");
		if(fa<0)putchar(')');
		printf(" %c ",op[i]);
		if(fb<0)putchar('(');
		if(cd!=0){
			printf("%d",fb*cd);	
			if(c!=0)putchar(' ');
		}
		if(cd==0&&fb<0)putchar('-');
		if(c!=0)printf("%d/%d",c,d);
		if(cd==0&&c==0)printf("0");
		if(fb<0)putchar(')');
		printf(" = ");
		if(i==0){
		if(b==0||d==0)printf("Inf");
			else{
			if(ansf1<0)printf("(");
			if(ansab1!=0){
				printf("%d",ansf1*ansab1);
				if(ansa1!=0)	putchar(' ');
			}
			if(ansab1==0&&ansf1<0)putchar('-');
			if(ansa1!=0)printf("%d/%d",ansa1,ansb1);
			if(ansab1==0&&ansa1==0)printf("0");
			if(ansf1<0)putchar(')');
		}
		}
		if(i==1){
			if(b==0||d==0)printf("Inf");
			else{
			if(ansf2<0)printf("(");
			if(ansab2!=0){
				printf("%d",ansf2*ansab2);
			if(ansa2!=0){
				putchar(' ');
			}
			}
			if(ansab2==0&&ansf2<0)putchar('-');
			if(ansa2!=0)printf("%d/%d",ansa2,ansb2);
			if(ansab2==0&&ansa2==0)printf("0");
			if(ansf2<0)putchar(')');
		}
		}
		if(i==2){
			if(ansb3==0||b==0||d==0)printf("Inf");
			else{
			if(ansf3<0)printf("(");
			if(ansab3!=0){
				printf("%d",ansf3*ansab3);
				if(ansa3!=0)putchar(' ');	
			}
			if(ansab3==0&&ansf3<0)putchar('-');
			if(ansa3!=0)printf("%d/%d",ansa3,ansb3);
			if(ansab3==0&&ansa3==0)printf("0");
			if(ansf3<0)putchar(')');
		}
		}
		if(i==3){
			if(ansb4==0||b==0||d==0)printf("Inf");
			else{
				if(ansf4<0)printf("(");
			if(ansab4!=0){
				printf("%d",ansf4*ansab4);
				if(ansa4!=0)putchar(' ');
			}
			if(ansab4==0&&ansf4<0)putchar('-');
			if(ansa4!=0)printf("%d/%d",ansa4,ansb4);
			if(ansab4==0&&ansa4==0)printf("0");
			if(ansf4<0)putchar(')');
			}
			
		}
	
		putchar('\n');
	}
	
	return 0;
}
