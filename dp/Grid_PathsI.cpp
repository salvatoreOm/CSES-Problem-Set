#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = (int)1e9+7;

void solve(){
    ll n;
    cin>>n;

    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i<n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>grid[i][j];
        }
    }

    //dp[i][j] -> Total Number of ways to go from i,j to n-1,m-1

    //dp[i+1][j] + dp[i][j+1]
    vector<vector<int>>dp(n,vector<int>(n));
    dp[n-1][n-1] = (grid[n-1][n-1] == '*' ? 0 : 1);

    for(int i = n-1 ; i >= 0 ; --i){
        for(int j = n-1 ; j >= 0 ; j--){
            if(i == n-1 && j == n-1){
                continue;
            }
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            }else{
                int ans1 = i < n-1 ? dp[i+1][j] : 0;
                int ans2 = j < n-1 ? dp[i][j+1] : 0;
                //transition
                dp[i][j] = (ans1+ans2)%M;
            }
        }
    }
    cout<<dp[0][0]<<endl;
}

int main(){
    solve();
    return 0;
}