#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define cntlD(x) __builtin_clz(x)

/*
    How & Why?
    
*/
void solve() {
    ll n,k;
    cin>>n>>k;
    ll tight = k;

    //when k is odd
    if(k & 1){
        for(int i = 0 ; i < k ; i++){
            cout<<n<<' ';
        }
        cout<<endl;
        return;
    }

    //when k is even
    vector<int>ans(k);
    int idx = 31 - cntlD(n);

    for(int i = idx ; i >= 0 ; i--){
        if((n >> i) & 1){
            ll leave;
            if(tight > 0){
                leave = tight - 1;
                tight--;
            }else{
                leave = 0;
            }
            for(int j = 0 ; j < k ; j++){
                if(j == leave) continue;
                ans[j] |= (1 << i);
            }
        }else{
            ll rem = k - tight;
            ll up = rem - (rem & 1);
            for(int j = k - 1; up; j-- , up--){
                ans[j] |= (1 << i);
            }
        }
    }

    for(int i = 0 ; i < k ; i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}