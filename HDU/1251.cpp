#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000000;
const int MAXM = 26;

struct Node{
	int val;
	Node *next[MAXM];
}pool[MAXN],*frog = pool,*root;

Node *New(){
	Node *ret = ++frog;
	FOR(i,0,25) ret->next[i] = NULL;
	ret->val = 0;
	return ret;
}

void insert(char *str){
	Node *v = root;
	int len = strlen(str);
	FOR(i,0,len-1){
		int x = str[i] - 'a';
		if(!v->next[x]) v->next[x] = New();
		v = v->next[x];
		v->val++;
	}
}

int calc(char *str){
	int len = strlen(str);
	Node *v = root;
	FOR(i,0,len-1){
		int x = str[i]-'a';
		if(!v->next[x]) return 0;
		v = v->next[x];
	}
	return v->val;
}

char str[500];
int N,M;

int main(){
	//freopen("a.in","r",stdin);
	root = New();
    while(gets(str)){
        if(str[0] == '\0') break;
        else insert(str);
    }
    while(~scanf("%s",str)){
		printf("%d\n",calc(str));
	}
	return 0;
}

