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

const int MAXN = 10000+5;

struct Node{
	struct Edge *firstEdge,*curEdge;
	int level;
}node[MAXN];

int n,N,S,T;

struct Edge{
	Node *s,*t;
	Edge *next,*reverse;
	int cap,flow;
}pool[1000000],*frog = pool;

Edge *New(Node *s,Node *t,int cap){
	Edge *ret = ++frog;
	*ret = (Edge){s,t,s->firstEdge,NULL,cap,0};
	return ret;
}

inline void add(int u,int v,int cap){
	node[u].firstEdge = New(&node[u],&node[v],cap);
	node[v].firstEdge = New(&node[v],&node[u],0);
	node[u].firstEdge->reverse = node[v].firstEdge;
	node[v].firstEdge->reverse = node[u].firstEdge;
}

struct Data{
	int x,y,z;
	
	bool operator < (const Data &other) const {
		return x < other.x && y < other.y && z < other.z;
	}
}d[MAXN];

bool bfs(Node *s,Node *t){
	FOR(i,0,N){
		node[i].curEdge = node[i].firstEdge;
		node[i].level = 0;
	}
	std::queue<Node *> q;q.push(s);
	s->level = 1;
	while(!q.empty()){
		Node *v = q.front();q.pop();
		for(Edge *e = v->firstEdge;e;e = e->next){
			if(e->flow < e->cap && !e->t->level){
				e->t->level = v->level + 1;
				if(e->t == t) return true;
				q.push(e->t);
			}
		}
	}
	return false;
}

int dfs(Node *v,Node *t,int limit=INT_MAX){
	int flow;
	if(v == t) return limit;
	for(Edge *&e = v->curEdge;e;e = e->next){
		if(e->flow < e->cap && e->t->level == v->level + 1){
			if((flow = dfs(e->t,t,std::min(limit,e->cap - e->flow))) > 0){
				e->flow += flow;
				e->reverse->flow -= flow;
				return flow;
			}
		}
	}
}

int dinic(){
	int ans = 0,flow = 0;
	while(bfs(&node[S],&node[T])){
		while((flow = dfs(&node[S],&node[T])) > 0){
			ans += flow;
		}
	}
	return ans;
}

inline void insert(int x,int y){ // addedge(x,y) -> dinic
	add(x,n+y,1);
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].z);
	N = (n<<1)+1;
	S = 0,T = N;
	FOR(i,1,n) FOR(j,1,n) if(d[i] < d[j]) insert(j,i);			
	FOR(i,1,n) add(S,i,1),add(i+n,T,1);
	printf("%d\n",n-dinic());
	return 0;
}
