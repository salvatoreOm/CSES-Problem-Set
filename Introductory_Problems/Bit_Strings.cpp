#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1e9 + 7;

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return res;
}


void solve() {
    /*
        How & Why?
        
    */
    ll n;
    cin>>n;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}