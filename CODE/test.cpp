#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool mycmp(int a,int b){  // ��Ϊ��K�����������Ƿǵݼ����ʶ��Զ���ص�����������ȱʡ��
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
        sort(tmp,tmp+(to-from+1),mycmp );          // ���ס������ȴ˴��ö������Ż���Ӱ��������
        printf("%d\n",tmp[k-1]);
    }
    return 0;
}
