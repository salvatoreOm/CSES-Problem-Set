#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string a,b;
    cin>>a>>b;

    int n = a.size(),m = b.size();

    //dp[i][j] -> Minimum steps to match the first i characters of first string with first j characters of second string.

    vector<vector<int>>dp(n+1,vector<int>(m+1,1e6));


    //base cases
    for(int i = 0 ; i<=n ; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j<=m ; j++){
        dp[0][j] = j;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            char x = a[i-1];
            char y = b[j-1];

            if(x == y){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j-1] + 1;
                dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
                dp[i][j] = min(dp[i][j],dp[i][j-1] + 1);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

int main(){
    solve();
    return 0;
}