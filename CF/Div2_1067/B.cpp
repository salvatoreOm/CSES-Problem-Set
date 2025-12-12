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
    vector<int>a(2*n);
    map<int,int>mp;
    for(int i = 0 ; i < (2*n) ; i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    

    ll ans = 0,cnto = 0;

    for(auto [x,y] : mp){
        if(y&1){
            ans++;
            cnto++;
        }
    }

    ll cnt = 0;
    for(auto [x,y] : mp){
        if(y & 1 ^ 1){
            if(y&2){
                ans+=2;
            }else{
                cnt++;
            }
        }
    }

    if(cnto < 2){
        cout<<ans + (2*(cnt-cnt%2))<<endl;
    }else{
        cout<<ans + 2*cnt<<endl;
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