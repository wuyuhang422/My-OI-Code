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
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;

const int MAXN = 300 + 5;
LL a[MAXN][MAXN];
LL N,ans;
bool vis[MAXN][MAXN],flag=true;

int main(){
	read(N);
	FOR(i,1,N) FOR(j,1,N) read(a[i][j]);
	//ans = N*(N-1);
	FOR(i,1,N) FOR(j,1,N) if(a[i][j]) ans++;
	FOR(k,1,N){
		FOR(i,1,N){
			FOR(j,1,N){
				if(i == j || i == k || j == k) continue;
				if(a[i][j] == a[i][k] +a[k][j]){
					ans--;
					a[i][j] = LLONG_MAX;
				}
				else if(a[i][j] > a[i][k] + a[k][j]){
					flag = false;
				}
			}
		}
	}
	printf("%lld\n",ans/2); 
	return 0;
} 
/*
3
0 1 1
1 0 1
1 1 0

*/
/*
5

0 361956 292566 145517 140463

361956 0 515281 507473 502419

292566 515281 0 328676 152103

145517 507473 328676 0 176573

140463 502419 152103 176573 0
*/
