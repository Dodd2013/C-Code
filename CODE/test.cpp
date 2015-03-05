#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool mycmp(int a,int b){  // 因为找K大数，排序是非递减，故而自定义回调函数而不用缺省的
    return a>b;
}
int num[10500];
int tmp[10500];
int main(){
    int nnum,nq;
    cin>>nnum;
    for(int i=1;i<=nnum;++i)scanf("%d",&num[i]);
    cin>>nq;
    int from,to,k;
    while(nq--){
        scanf("%d%d%d",&from,&to,&k);
        for(int i=from,j=0;i<=to;++i,++j)tmp[j]=num[i];
        sort(tmp,tmp+(to-from+1),mycmp );          // 赵伦、田永先此处用堆排序优化，影响力不大
        printf("%d\n",tmp[k-1]);
    }
    return 0;
}
