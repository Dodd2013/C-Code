#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char per[15]="74112243735566";
bool p[14];
int main()
{
	int i;
	do
	{
		if(per[1]!='4') break;
		memset(p,0,sizeof(p));
		for(i=0;i<14;i++)
		{
			if(!p[i])
			{
				if(per[i]==per[i+per[i]-47])
					p[i]=p[i+per[i]-47]=1;
				else break;	
			}
		}
		if(i==14) puts(per);
	}while(next_permutation(per+2,per+14));
}
