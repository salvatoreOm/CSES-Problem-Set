#include<bits/stdc++.h>
using namespace std;
const int M = (int)1e9+7;

bool isValid(int x, int m){
    return x>=1 && x<=m;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int>a(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(m+1));
    //dp[i][k] = number of ways to build a prefix of size i such that the last element of the prefix is k

    //base case
    for(int i = 1 ; i<=m ; i++){
        if(a[0] == i || a[0] == 0){
            dp[1][i] = 1;
        }
    }

    for(int i = 2 ; i <= n ; i++){
        for(int k = 1 ; k <= m ; k++){
            if(a[i-1] != 0 && a[i-1] != k){
                dp[i][k] = 0;
                continue;
            }
            for(int prev = k-1 ; prev <= k+1 ; prev++){
                if(!isValid(prev,m)){
                    continue;
                }
                dp[i][k] = (dp[i][k] + dp[i-1][prev])%M;
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i<=m ; i++){
        ans = (ans + dp[n][i])%M;
    }
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}