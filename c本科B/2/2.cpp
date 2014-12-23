#include <cstdio>
int main() {
	double s=0.0;
	int i;
	for(i=1;s<=15.0;i++){
		s+=1.0/i;
	}
	printf("%d",i-1);
	return 0;
}
