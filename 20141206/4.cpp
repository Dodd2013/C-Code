#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef struct {
	string m;
	int ci;	
}D;
int flag=0;
map<string,char> maps;
string b;
int check(D t){
	if(maps[t.m]==1)return 1;
	if(t.m==b){
		flag=1;
		cout<<t.ci;
	}
	return 0;	
}
void swap(char *a,char*b){
	char t=*a;
	*a=*b;
	*b=t;
}
int main() {
	string a;
	cin>>a>>b;
	queue<D> q;
	int op[4]={-1,1,-3,3};
	D l;
	l.ci=0;
	l.m=a;
	q.push(l);
	maps[l.m]=1;
	while(!q.empty()){
		D t;
		int x;
		t=q.front();
		q.pop();
		for(int i=0;i<9;i++){
			if(t.m[i]=='.'){
				x=i;break;
			}
		}
		t.ci++;
		for(int i=0;i<4;i++){
			if(x+op[i]>=0&&x+op[i]<9){
				if(op[i]==-1&&(x==3||x==6))continue;
				if(op[i]==1&&(x==2||x==5))continue;
				swap(&t.m[x],&t.m[x+op[i]]);
				if(!check(t)){
					q.push(t);
					maps[t.m]=1;
				}
				swap(&t.m[x],&t.m[x+op[i]]);
			}
		}
		t.ci--;
		if(flag)break;
	}
	return 0;
}
