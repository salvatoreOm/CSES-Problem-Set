#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    
    
*/
void solve() {
    int n;string s;
    cin>>n>>s;
    string t = s + s;
    //Just check pairs of 1's and 0's and increase the counter greedily as we have fixed 1 unit cost

    //Or simply in front of a 1, how many consecutive maxi 0's arrive.
    int maxi = 0, cur = 0;

    for(char c : t) {
        if (c == '0') {
            cur++;
            maxi = max(maxi, cur);
        } else {
            cur = 0;  
        }
    }
    cout<<maxi<<endl;
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