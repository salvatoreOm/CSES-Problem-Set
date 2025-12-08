#include<bits/stdc++.h>
using namespace std;
using ll = long long;

long long binPow(ll a,ll b){
    //Awesome Trick O(Logn) as we have logn+1 steps for mul
    ll res = 1;
    while(b > 0){
        if(b&1){
            res = res*a;
        }
        a = a*a;
        b >>= 1;
    }
    return res;
}



void solve(){
    cout<<binPow(2,3)<<endl;
}

int main(){
    solve();
    return 0;
}