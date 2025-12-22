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

// FIXED: use ll for base
ll powL(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    } 
    return res;
}

/*
    How & Why?
    
*/
void solve() {
    ll n; 
    cin >> n;

    ll cnt = 0;
    vector<ll> ans;

    for(int k = 1; k <= 17; k++){
        ll p = powL(10LL, k) + 1; 
        if(p > n) break;

        if(n % p == 0){
            cnt++;
            ans.push_back(n / p);
        }
    }

    if(cnt == 0){
        cout << 0 << endl;
        return;
    }

    cout << cnt << endl;
    reverse(ans.begin(), ans.end());
    for(ll X : ans){
        cout << X << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
