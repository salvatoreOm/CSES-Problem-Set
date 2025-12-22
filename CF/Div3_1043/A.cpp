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
    int n;cin>>n;    
    string a; cin>>a;
    int m; cin>>m;
    string b; cin>>b;
    vector<char>moves(m);
    for(char &c : moves){
        cin>>c;
    }
    string ans = a;

    for(int i = 0 ; i < m ; i++){
        if(moves[i] == 'V'){
            ans = b[i] + ans;
        }else{
            ans += b[i];
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}