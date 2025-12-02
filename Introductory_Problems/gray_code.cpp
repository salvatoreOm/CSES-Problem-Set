#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
2 -> 10

*/

void solve(){
    ll n;cin>>n;

    ll tot_subs = (1<<n);

    for(int i = 0 ; i < tot_subs ; i++){
        int gray = i ^ (i >> 1);
        for(int j = n-1 ; j >= 0 ; j--){
            bool bit = ((gray >> j) & 1);
            cout<<bit;
        }
        cout<<endl;
    }
}

int main(){
    solve();
    return 0;
}