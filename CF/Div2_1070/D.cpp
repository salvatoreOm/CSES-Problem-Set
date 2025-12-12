#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

const ll M = 998244353;
/*
    How & Why?
    
*/

ll func(ll node, ll sum, vector<ll>&av, vector<vector<ll>>&adjLis,map<pair<ll,ll>,ll>&dp){
    if(dp.find({node,sum}) != dp.end()) return dp[{node,sum}];

    ll temp = 0;
    for(auto it : adjLis[node]){
        if(av[it] == sum) temp += func(it,av[node] + av[it],av,adjLis,dp);
        temp %= M;
    }
    return dp[{node,sum}] = (temp+1)%M;
}

void solve() {
    ll n,m;
    cin>>n>>m;

    vector<ll>av(n);
    for(ll i = 0 ; i<n ; i++){
        cin>>av[i];
    }
    vector<vector<ll>>adjLis(n);
    vector<vector<ll>>edges;
    map<pair<ll,ll>,ll>dp;

    ll ans = 0;
    for(ll i = 0 ; i<m ; i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;

        adjLis[a].push_back(b);
        edges.push_back({a,b});
    }

    for(auto it : edges){
        ll a = it[0];
        ll b = it[1];

        ll v1 = av[a];
        ll v2 = av[b];

        ans += func(b,v1+v2,av,adjLis,dp);
        ans %= M;
    }
    cout<<ans%M<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}