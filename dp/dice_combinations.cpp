#include<bits/stdc++.h>
using namespace std;
const int M = (int)1e9+7;
void solve(){
    int n;
    cin>>n;

    vector<int>dp(n+1);
    //dp[i] -> Number of ways to create a sum i
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if(j <= i){
                dp[i] = (dp[i] + dp[i-j])%M;
            }
        }
    }
    cout<<dp[n]<<endl;
}

int main(){
    solve();
    return 0;
}