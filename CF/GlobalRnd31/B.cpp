#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    
*/
void solve() {
    int n;cin>>n;
    vector<string>v(n);
    for(int i= 0 ; i <n ; i++){
        cin>>v[i];
    }

    string ans = "";

    for(int i = 0 ; i<n ; i++){
        string s1 = ans + v[i];
        string s2 = v[i] + ans;
        if(s1 > s2){
            ans = v[i] + ans;
        }else{
            ans += v[i];
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