#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    
    
*/
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int neg = -1,ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            neg = max(neg, i + k);
        } else {
            if (i > neg) ans++;  
        }
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