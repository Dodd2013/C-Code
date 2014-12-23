#include <cstdio>
#include <vector>
#include <algorithm>
#define min(x,y) (x>y?y:x)
using namespace std;
typedef struct {
	int x,y,cost;	
}D;
int par[100000],rank[100000];
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rank[i]=0;
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
	if(rank[x]<rank[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rank[x]==rank[y])rank[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}
vector<D> v;
int cmp(D a,D b){
	if(b.cost<a.cost)return 0;
	return 1;
}
int main() {
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		D u;
		scanf("%d%d%d",&u.x,&u.y,&u.cost);
		v.push_back(u);
	}
	sort(v.begin(),v.end(),cmp);
	init(n);
	for(int i=0;i<v.size();i++){
		if(!(same(v[i].x,v[i].y))){
			unite(v[i].x,v[i].y);
			ans+=v[i].cost;
		}
	}
	printf("%d",ans);
	return 0;
}
