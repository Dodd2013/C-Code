#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <map>
using namespace std;
struct Node{
	int pos[2], ans;
	char flag;
	char s[41];
};
bool check( char s[]){
	for (int i = 7; i<26; i += 6){
		char ch = s[i], flag = 1;
		for (int j = 0; j<4; j++){
			if (s[i + j] != ch){
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return true;
	}
	for (int i = 7; i<11; i++){
		char ch = s[i], flag = 1;
		for (int j = 0; j<19; j += 6){
			if (s[i + j] != ch){
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return true;
	}
	char ch = s[20], flag = 1;
	for (int j = 10; j<26; j += 5){
		if (s[j] != ch){
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return true;
	ch = s[7];
	flag = 1;
	for (int j = 7; j<29; j += 7){
		if (s[j] != ch){
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return true;
	return false;
}
map<string,bool> ma;
int main(){
	char m[41];
	memset(m, 1, 41);
	queue<Node> q;
	for (int i = 7; i < 30; i += 6){
		scanf("%s", m + i);
		m[i + 4] = 1;
	}
		

	Node n;
	for (int i = 0, j = 0; i<=28; i++){
		if (m[i] == 'O'){
			n.pos[j++] = i;
		}
	}
	n.ans = 0;
	n.flag = 'O';
	memcpy(n.s, m,40);
	q.push(n);
	while (!q.empty()){
		Node t = q.front();
		q.pop();
		int op[4] = { 1, -1, 6, -6 };
		for (int j = 0; j<2; j++){
			for (int i = 0; i<4; i++){
				int posn = t.pos[j] + op[i];
				if (t.s[posn] != 1 && t.s[posn] != 'O'){
					if (t.flag != t.s[posn]){
						n.ans = t.ans + 1;
						n.flag = t.s[posn];
						n.pos[0] = t.pos[j == 1 ? 0 : 1];
						n.pos[1] = posn;
						char ch = t.s[posn]; t.s[posn] = t.s[t.pos[j]]; t.s[t.pos[j]] = ch;
						string sd =string(t.s);
						if (ma[sd]==NULL){
							if (check(t.s)){
								printf("%d\n", n.ans);
								return 0;
							}
							strcpy(n.s, t.s);
							q.push(n);
							ma[string(t.s)] = true;
						}
						ch = t.s[posn]; t.s[posn] = t.s[t.pos[j]]; t.s[t.pos[j]] = ch;
					}
				}
			}
		}
	}
	return 0;
}
