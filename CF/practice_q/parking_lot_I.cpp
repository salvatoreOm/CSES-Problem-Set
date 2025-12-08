#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
/*
    How & Why?
    Permutation and Combination Simple
    
*/

ll binPow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b&1){
            res = res*a;
        }
        a = a*a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;cin>>n;
    ll end = (binPow(4,n-3)*24);
    ll mid = 36*(n-3)*binPow(4,n-4);
    ll ans = end + mid;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}