#include <cstdio>
#include <vector>
#include <algorithm>
#define min(x,y) (x>y?y:x)
using namespace std;
typedef struct {
	int x,y,cost;	
}D;
int par[100000];
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
	}
}
int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	else{
		par[y]=x;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}
vector<D> v;
bool cmp(D a,D b){
	return b.cost>a.cost;
}
int main() {
	int n,m,ans=0,flag=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		D u;
		scanf("%d%d%d",&u.x,&u.y,&u.cost);
		v.push_back(u);
	}
	sort(v.begin(),v.end(),cmp);
	init(n);
	for(int i=0;i<v.size();i++){
		if(!(same(v[i].x,v[i].y))||v[i].cost<0){
			unite(v[i].x,v[i].y);
			ans+=v[i].cost;
		}
	}
	//printf("%d",ans);
	int root;
	for(int i=1;i<=n;i++){
		root=find(i);
	}
	for(int i=1;i<=n;i++){
		if(par[i]!=root)flag=1;
	}
	for(int i=0;i<n;i++){
		D u;
		int cost;
		scanf("%d",&cost);
		if(cost<0)continue;
		u.x=i+1;u.y=0;u.cost=cost;
		v.push_back(u);
	}
	sort(v.begin(),v.end(),cmp);
	init(n+1);
	int t=0;
	for(int i=0;i<v.size();i++){
		if(!(same(v[i].x,v[i].y))||v[i].cost<0){
			unite(v[i].x,v[i].y);
			t+=v[i].cost;
		}
	}
	if(t<ans)ans=t;
	if(flag)ans=t;
	printf("%d\n",ans);
	return 0;
}

