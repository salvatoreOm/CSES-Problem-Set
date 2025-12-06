#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    Keep track of mini and maxi, and return maxi.
    
*/
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll mini{0},maxi{0};   

    for (int i = 0; i < n; i++) {
        ll ai = a[i], bi = b[i];
        ll maxe = max(maxi - ai, bi - mini);
        ll mine = min(mini - ai, bi - maxi);

        maxi = maxe;
        mini = mine;
    }

    cout<<maxi<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}