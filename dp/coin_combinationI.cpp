#include<bits/stdc++.h>
using namespace std;
const int M = (int)1e9+7;

void solve(){
    int n,x;
    cin>>n>>x;

    vector<int>c(n);
    for(int &a : c) cin>>a;

    vector<int>dp(x+1,0);
    //dp[i] -> Total number of ways to construct a sum of i


    dp[0] = 1;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(c[j] <= i){
                dp[i] = (dp[i] + dp[i-c[j]])%M;
            }
        }
    }
    cout<<dp[x]<<endl;
}

int main(){
    solve();
    return 0;
}