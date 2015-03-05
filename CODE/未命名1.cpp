#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int cmp(const void *p1, const void *p2){
	return *(int *)(p2)-*(int *)(p1);
}
int main(){
	int a[3]={2,8,6};
	qsort(a,3,sizeof(int),cmp);
	for(int i=0;i<3;i++){
		std::cout<<a[i];
	}
} 
