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
ll func(ll x){
    ll val = pow(3,x+1) + x * pow(3,x-1);
    return val;
}

void solve() {
    ll n;
    cin>>n;
    ll c;
    ll ans = 0, sum = 0;

    while(n > 0){
        c = log(n)/log(3);

        if(pow(3,c+1) == n){
            c = c + 1;
        }
        ans += func(c);
        c = pow(3,c);
        n = n - c;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}