#include <cstdio>
#include <vector>
using namespace std;
int main(){
	char ch[1000];
	while(~scanf("%s",ch)){
		vector<char> v;
		int i;
		bool flag=false;
		for(i=0;ch[i]!='\0';i++){
			if(ch[i]=='\0'||ch[i]=='*'||ch[i]=='|'||ch[i]=='('||ch[i]==')'||ch[i]=='1'||ch[i]=='0'){
			if(i!=0&&ch[i-1]=='|'){
				if(ch[i]=='*'||ch[i]=='\0'||ch[i]==')'||ch[i]=='|'){
					flag=true;
					continue;
				}
			}
			if(ch[i]=='*'){
				if(i==0||ch[i-1]=='('||ch[i-1]=='|'){
					flag=true;
					continue;
				}
			}else if(ch[i]=='('){
				v.push_back(ch[i]);
			}else if(ch[i]==')'){
				if(v.empty()||i==0||ch[i-1]=='|'||v.back()!='('||ch[i-1]=='('){
					flag=true;
					continue;
				}
				v.pop_back();
			}else if(ch[i]=='|'){
				if(i==0||ch[i-1]=='('||ch[i-1]=='|'){
					flag=true;
					continue;
				}
			}
		}
		else{
			flag=true;
			continue;
		}
		}
		if(flag||!v.empty()||ch[i-1]=='|'){
			printf("no\n");
			continue;
		}
		printf("yes\n");
	}
	return 0;
} 
