#include <cstdio>
#define MAXN 200000
#include <algorithm>  
using namespace std;
int a[MAXN << 2];
void PushUP(int cur){
	a[cur] = max(a[cur << 1],a[cur << 1 | 1]);
}
void build(int l, int r, int cur){
	if (l == r){
		scanf("%d", &a[cur]);
	}
	else{
		int m = (l + r) >> 1;
		build(l, m, cur << 1);
		build(m + 1, r, cur << 1 | 1);
		PushUP(cur);
	}
}
void update(int id, int add, int l, int r, int cur){
//	int m = (l + r) >> 1;
//	if (l == m){
//		a[cur] =add;
//	}
//	else if (id >= l&&id <= m){
//		update(id, add, l, m, cur << 1);
//		PushUP(cur);
//	}
//	else if (id>m&&id <= r){
//		update(id, add, m + 1, r, cur << 1 | 1);
//		PushUP(cur);
//	}
if (l == r) {  
        a[cur] = add;  
        return ;  
    }  
    int m = (l + r) >> 1;  
    if (id <= m) update(id , add , l, m, cur << 1);  
    else update(id , add ,  m + 1, r, cur << 1 | 1);  
    PushUP(cur);  
}
int query(int L, int R, int l, int r, int cur){
	if (L <= l&&R >= r)return a[cur];
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret = max(query(L, R, l, m, cur << 1),ret);
	if (R > m) ret = max(query(L, R, m + 1, r, cur << 1 | 1), ret);
	return ret;
}
int main(){
	int n, m;
	while(~scanf("%d%d", &n, &m)){
			build(1, n, 1);
	while (m--){
		char op[20];  
            int a , b;  
            scanf("%s%d%d",op,&a,&b);  
            if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));  
            else update(a , b , 1 , n , 1);  
	}
	}
}
