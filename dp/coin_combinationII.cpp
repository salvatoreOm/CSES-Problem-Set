#include<bits/stdc++.h>
using namespace std;
const int M = (int)1e9+7;

void solve(){
    int n,x;
    cin>>n>>x;

    vector<int>c(n);
    for(int &z : c)cin>>z;

    //dp[i][k]->Total number of ways to construct a sum of k, provided we pick coins from ci to cn and before ci are not pickable.

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));


    //base case
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = 1;
    }

    for(int i = n-1 ; i >= 0 ; i--){
        for(int k = 1 ; k <= x ; k++){
            int notPick = dp[i+1][k];
            int pick = 0;
            if(c[i] <= k){
                pick = dp[i][k-c[i]];
            }
            dp[i][k] = (notPick+pick)%M;
        }
    }

    cout<<dp[0][x]<<endl;
}

int main(){
    solve();
    return 0;
}