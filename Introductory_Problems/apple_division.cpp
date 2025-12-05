#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

vector<ll>a;
ll ans = LLONG_MAX;
ll S;
int n;


void solve(int i, ll sumA) {
    if(i == n){
        ans = min(ans,abs(S - 2*sumA));
        return;
    }

    solve(i+1,sumA + a[i]);
    solve(i+1,sumA);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    a.resize(n);

    for(int i = 0 ; i<n ; i++) cin>>a[i];

    S = accumulate(a.begin(),a.end(),0LL);
    solve(0,0LL);

    cout<<ans;
}