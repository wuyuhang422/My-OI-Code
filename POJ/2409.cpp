/*
 * Author: RainAir
 * Time: 2019-08-20 20:25:21
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
int n,m;

inline int gcd(int a,int b){
    return !b ? a : gcd(b,a%b);
}

inline int qpow(int a,int n){
    int res = 1ll;
    while(n){
        if(n & 1) res = 1ll*res*a;
        a = 1ll*a*a;
        n >>= 1;
    }
    return res;
}

inline void Solve(){
    int ans = 0;
    FOR(i,1,n) ans += qpow(m,gcd(n,i));
    ans += (n&1) ? (n*qpow(m,n/2+1)) : (n/2*qpow(m,n/2)+n/2*qpow(m,n/2+1));
    ans = 1ll*ans/n/2;
    printf("%lld\n",ans);
}

signed main(){
    while(~scanf("%lld%lld",&m,&n) && (n+m)) Solve();
    return 0;
}
