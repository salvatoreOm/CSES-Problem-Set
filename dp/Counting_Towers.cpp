#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = (int)1e9+7;

vector<vector<int>>dp(1e6+1,vector<int>(2));

void solve(){
    ll n;cin>>n;

    //dp[i][0]-> Number of ways to fill up the grid from ith row to the top such that there is a 1*2 block on the i-1th row trying to extend forward.

    //dp[i][1]-> Number of ways to fill up the grid from ith row to the top such that there are 2 1*1 blocks on the i-1th row trying to extend forward.


    dp[n][0] = 1;
    dp[n][1] = 1;

    for(int i = n-1 ; i >= 0 ; i--){
        dp[i][0] = (2LL * dp[i+1][0] + dp[i+1][1])%M;
        dp[i][1] = (4LL * dp[i+1][1] + dp[i+1][0])%M;
    }
    cout<<(dp[1][0] + dp[1][1])%M<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}