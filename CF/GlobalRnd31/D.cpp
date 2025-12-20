#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    
*/
void solve() {

    //inputs
    int n; cin>>n;
    vector<ll>x(n);
    for(int i = 0 ; i < n ; i++){
        cin>>x[i];
    }
    x.push_back(1e15);
    //diff array for distance
    vector<ll>d(n);
    for(int i = 0 ; i < n ; i++){
        d[i] = x[i+1] - x[i];
    }

    //main logic
    ll ans = 0;
    ll low = 0, high = d[0];

    for(int i = 1 ; i < n ; i++){
        ll nl = d[i-1] - high;
        ll nh = d[i-1] - low;

        nh = min(nh, d[i]);
        if(nl >= d[i]){
            nl = 0;
        }else{
            ans++;
        }
        low = nl;
        high = nh;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}