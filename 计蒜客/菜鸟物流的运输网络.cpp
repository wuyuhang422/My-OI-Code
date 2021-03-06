#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
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
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 500+5;
const int MAXM = MAXN*MAXN;

struct Node{
    struct Edge *first,*cur;
    int level,num;        
}node[MAXN];

struct Edge{
    Node *s,*t;
    int cap,flow;
    Edge *next,*rev;
}pool[MAXM<<1],*frog = pool;

Edge *New(Node *s,Node *t,int cap){
    Edge *ret = frog;
    *ret = (Edge){s,t,cap,0,s->first,NULL};
    frog++;
    return ret;
}

inline void add(int u,int v,int cap){
    node[u].first = New(&node[u],&node[v],cap);
    node[v].first = New(&node[v],&node[u],0);
    node[u].first->rev = node[v].first;
    node[v].first->rev = node[u].first;
}

int N,S,T;

inline bool bfs(Node *s,Node *t){
    FOR(i,0,N){
        node[i].cur = node[i].first;
        node[i].level = 0;
    }
    std::queue<Node *> q;q.push(s);
    s->level = 1;
    while(!q.empty()){
        Node *v = q.front();q.pop();
        for(Edge *e = v->first;e;e = e->next){
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
    if(v == t) return limit;
    int flow;
    for(Edge *&e = v->cur;e;e = e->next){
        if(e->flow < e->cap && e->t->level == v->level + 1){
            if((flow = dfs(e->t,t,std::min(limit,e->cap-e->flow)))){
                e->flow += flow;
                e->rev->flow -= flow;
                return flow;
            }
        }
    }
    return 0;
}

inline int dinic(){
    int ans = 0,flow;
    while(bfs(&node[S],&node[T])){
        while((flow = dfs(&node[S],&node[T]))){
            ans += flow;
        }
    }
    return ans;
}

int n,m,a,b,mid;

inline void init(){
    CLR(node,0);CLR(pool,0);frog = pool;
    FOR(i,0,MAXN-1) node[i].num = i;
}

inline void Solve(){
    init();
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&mid);
    S = 0,T = n*2+1;N = T;
    add(S,mid,2);
    FOR(i,1,n){
        if(i == mid){
            add(i,i+n,2);
            continue;
        }
        add(i,i+n,1);
        if(i == a || i == b) add(i+n,T,1);
    }
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        add(u+n,v,INT_MAX);
        add(v+n,u,INT_MAX);
    }
    dinic();
    std::vector<int> ans;
    int v = a;
    while(true){
        if(v <= n && v >= 1) ans.push_back(v);
        int pos = -1;
        for(Edge *e = pool;e != frog;e++){
            // DEBUG(e);
            if(e->t->num == v)
                if(e->rev->cap - e->rev->flow > 0){
                    pos = e->s->num;
                    break;
                }
        }
        if(pos == S) break;
        v = pos;
    }
    v = b;std::vector<int> ans2;
    while(true){
        if(v <= n && v >= 1) ans2.push_back(v);
        int pos = -1;// DEBUG(v);
        for(Edge *e = pool;e != frog;e++){
            // DEBUG(e->t->num);
            if(e->t->num == v){
                // DEBUG(e->rev->cap);DEBUG(e->rev->flow);
                if(e->rev->cap - e->rev->flow > 0){
                    pos = e->s->num;
                    break;
                }
            }
        }
        if(pos == mid) break;
        v = pos;
        //if(v == -1) break;
    }
    int cnt = 0;
    FOR(i,0,(int)ans.size()-1) printf("%d ",ans[i]); 
    ROF(i,(int)ans2.size()-1,0) printf("%d ",ans2[i]);
    puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}