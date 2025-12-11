#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    
    
*/
void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i <n ; i++){
        cin>>a[i];
    }
    int ans = 0;
    //vis
    vector<int>vis(n,0);
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i ; j < n ; j++){
            if(!vis[j]){
                if(a[i] > a[j]){
                    ans++;
                    vis[j] = 1;
                }
            }
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