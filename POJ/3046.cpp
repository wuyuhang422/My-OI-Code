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
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e7 + 5;
const int ha = 1000000;

int T,A,S,B;
int a[MAXN],f[2][MAXN],now;

int main(){
    scanf("%d%d%d%d",&T,&A,&S,&B);
    FOR(i,1,A){
        int x;scanf("%d",&x);a[x]++;
    }
    f[now][0] = f[now^1][0] = 1;
    FOR(i,1,T){
        now ^= 1;
        FOR(j,1,B){
            if(j-a[i]-1 >= 0) f[now][j] = (f[now^1][j]+f[now][j-1]-f[now^1][j-a[i]-1]+ha)%ha;
            else f[now][j] = (f[now^1][j]+f[now][j-1])%ha;
        }
        //now ^= 1;
    }
    int ans = 0;
    FOR(i,S,B) (ans += f[now][i]) %= ha;
    printf("%d\n",ans);
    return 0;
}