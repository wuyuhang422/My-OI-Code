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

#define fi first
#define lc (ch[x][0])
#define se second
#define U unsigned
#define rc (ch[x][1])
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100000+5;
int ch[MAXN][2],f[MAXN],son[MAXN],size[MAXN],rev[MAXN];

inline bool nroot(int x){
    return ch[f[x]][0] == x || ch[f[x]][1] == x;
}

inline void pushup(int x){
    size[x] = size[lc] + size[rc] + son[x] + 1;
}

inline void reverse(int x){
    std::swap(lc,rc);rev[x] ^= 1;
}

inline void pushdown(int x){
    if(rev[x]){
        if(lc) reverse(lc);
        if(rc) reverse(rc);
        rev[x] = 0;
    }
}

inline void rotate(int x){
    int y = f[x],z = f[y],k = ch[y][1] == x,w = ch[x][!k];
    if(nroot(y)) ch[z][ch[z][1] == y] = x;
    ch[x][!k] = y;ch[y][k] = w;
    if(w) f[w] = y;
    f[y] = x;f[x] = z;
    pushup(y);
}

int st[MAXN];

inline void splay(int x){
    int y = x,z;st[z = 1] = y;
    while(nroot(y)) st[++z] = y = f[y];
    while(z) pushdown(st[z--]);
    while(nroot(x)){
        y = f[x],z = f[y];
        if(nroot(y)) rotate((ch[y][0] == x) ^ (ch[z][0] == y) ? x : y);
        rotate(x);
    }
    pushup(x);
}

inline void access(int x){
    for(int y = 0;x;x = f[y = x]){
        splay(x);son[x] += size[rc] - size[y];
        rc = y;pushup(x);
    }
}

inline void makeroot(int x){
    access(x);splay(x);reverse(x);
}

inline void link(int x,int y){
    makeroot(x);makeroot(y);f[x] = y;
    son[y] += size[x];pushup(y);
}

int main(){
    int N,M;scanf("%d%d",&N,&M);
    FOR(i,1,M){
        char str[20];int x,y;
        scanf("%s%d%d",str+1,&x,&y);
        if(str[1] == 'A'){
            link(x,y);
        }
        if(str[1] == 'Q'){
            makeroot(x);makeroot(y);
            printf("%d\n",size[x]*(size[y]-size[x]));
        }
    }
    return 0;
}