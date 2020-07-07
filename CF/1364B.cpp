/*
 * Author: RainAir
 * Time: 2020-06-14 14:48:29
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
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int a[MAXN],n;

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    std::vector<int> ans;ans.pb(a[1]);
    FOR(i,2,n-1){
        if(a[i-1] <= a[i] && a[i] >= a[i+1]){
            ans.pb(a[i]);
        }
        else if(a[i-1] >= a[i] && a[i] <= a[i+1]){
            ans.pb(a[i]);
        }
    }
    ans.pb(a[n]);
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
