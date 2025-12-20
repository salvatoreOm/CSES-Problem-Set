#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    
*/
void solve() {
    int l,a,b;
    cin>>l>>a>>b;

    int ans = a;

    for(int k = 0 ; k <= l-1 ; k++){
        int sum = (a + (k*b)) % l;
        ans = max(ans,sum);
    }
    cout<<ans<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}