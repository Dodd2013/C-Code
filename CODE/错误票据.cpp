#include <cstdio>
#include <cstring>
int main() {
	int n,c,min=100000,max=0;
	char s[1000000],a[100000]={0};
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(s);
        char *r=strtok(s," ");
    	while(r!= NULL ) {
    		int i;
			sscanf(r,"%d",&i);
			if(a[i])c=i;
			else a[i]=1;
			if(i<min)min=i;
			if(i>max)max=i;
      	   	r= strtok(NULL," ");
   	 	}
	}
	for(int i=min+1;i<max;i++){
		if(!a[i]){
			printf("%d %d\n",i,c);
			break;
		}
	}
	return 0;
}
