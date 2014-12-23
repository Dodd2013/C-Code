#include <cstdio>
#include <cmath>
int main() {
	double x=2.4;
	for(;x<3;x+=0.00000001){
		if(fabs(pow(x,x)-10.0)<0.000001){
			printf("%.8lf\n",x);
		}
	}
	return 0;
}
