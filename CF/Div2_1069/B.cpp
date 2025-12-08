#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    Create a prefix array, then output 
    
*/
void solve() {
    int n,l,r;
    cin>>n>>l>>r;

    vector<int>pre(n+1,0);

    for(int i = 1 ; i <= n ; i++){
        if(i == r){
            pre[r] = pre[l-1];
            continue;
        }
        pre[i] = i;
    }

    for(int i = 0 ; i < n ; i++){
        cout<<(pre[i+1]^pre[i])<<' ';
    }

    cout<<endl;
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