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
	for(int i=0;i<=n;i++){
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
	par[y]=x;
}
bool same(int x,int y){
	return find(x)==find(y);
}
vector<D> v;
int cmp(D a,D b){
	return b.cost>a.cost;
}
int main() {
	int n,m,ans=0,maxday=0,root=1,flag,t=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		D u;
		scanf("%d%d%d",&u.x,&u.y,&u.cost);
		v.push_back(u);
		if(u.cost>maxday)maxday=u.cost;
	}
	sort(v.begin(),v.end(),cmp);
	for(int day=0,k=0;k<v.size();k++,day=v[k].cost){
		if(day==v[k-1].cost)continue;
		init(n);
		flag=0;
		int root2=0;
		for(int i=t;i<v.size();i++){
			if(v[i].cost<=day){
				t=i;
				continue;
			}
			unite(v[i].x,v[i].y);
		}
		for(int j=1;j<=n;j++){
				if(find(j)==j)root2++;
			}
		if(root<root2){
			ans++;
			root=root2;	
		}
	}
	printf("%d",ans);
	return 0;
}

