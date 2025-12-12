#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

struct triplet{
    int x, y, gcd;
};

triplet extendedEuclid(int a, int b){
    if(b == 0){
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }

    triplet sA = extendedEuclid(b, a % b);
    triplet ans;
    ans.gcd = sA.gcd;
    ans.x = sA.y;
    ans.y = sA.x - (a / b) * sA.y;
    return ans;
}

ll modInverse(ll a, ll m){
    triplet t = extendedEuclid((int)((a % m + m) % m), (int)m);
    if(t.gcd != 1) return -1;
    return ((ll)t.x % m + m) % m;
}

/*
    How & Why?
    
*/
void solve() {
    int n;
    cin>>n;

    int y,r;
    cin>>y>>r;

    // if(r >= n){
    //     cout<<n<<endl;
    //     return;
    // }

    // int ans = 0;
    // ans += r;
    // int x = y/2;

    // if(x >= n){
    //     cout<<n<<endl;
    //     return;
    // }

    // ans+=x;
    int ans = 0;
    ans += r;
    ans += y/2;

    if(ans >= n){
        cout<<n<<endl;
    }else{
        cout<<ans<<endl;
    }
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