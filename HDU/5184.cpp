/*
 * Author: RainAir
 * Time: 2019-08-26 17:13:50
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1000000+5;
const int ha = 1000000007;

int fac[MAXN],inv[MAXN];

inline int qpow(int a,int n=ha-2){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

inline void prework(){
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);
    ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
    if(n < m) return 0;
    return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

char str[MAXN];
int n;

inline void Solve(){
    scanf("%s",str+1);int len = strlen(str+1);
    if(n&1){
        puts("0");return;
    }
    int l=0,r=0;
    FOR(i,1,len){
        if(str[i] == '(') ++l;
        else ++r;
        if(r > l){
            puts("0");return;
        }
    }
    int m = n/2;
    l = m-l;r = m-r;
//    DEBUG(l);DEBUG(r);
    printf("%lld\n",(C(l+r,l)-C(l+r,r+1)+ha)%ha);
}

signed main(){
    prework();
    while(~scanf("%lld",&n)) Solve();
    return 0;
}
