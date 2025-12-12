#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;

    vector<int>c(n);
    for(int &it : c) cin>>it;

    vector<int>dp(x+1,1e9);
    //dp[k] -> Minimum Number of coins required to construct a sum of K
    dp[0] = 0;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(c[j] <= i){
                dp[i] = min(dp[i],dp[i-c[j]] + 1);
            }
        }
    }
    cout<<(dp[x] < 1e9 ? dp[x] : -1)<<endl;
}

int main(){
    solve();
    return 0;
}