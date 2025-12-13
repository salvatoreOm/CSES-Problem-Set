#include<iostream>
#include<vector>
using namespace std;
using ll = long long;


void solve(){
    ll n,x;
    cin>>n>>x;

    vector<int>h(n),s(n);
    for(int &i : h) cin>>i;
    for(int &i : s) cin>>i;

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));

    for(int i = 1;  i<=n ; i++){
        for(int j = 0 ; j<=x ; j++){
            int w = h[i-1];
            int v = s[i-1];

            int pick = (j >= w ? dp[i-1][j-w] + v : 0);
            int skip = dp[i-1][j];

            dp[i][j] = max(skip,pick);
        }   
    }
    cout<<dp[n][x]<<endl;
}


int main(){
    solve();
    return 0;
}