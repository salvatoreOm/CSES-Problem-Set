#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll INF = 2e18;

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
    int n,cntE{0},cntO{0};
    cin>>n;

    vector<int>a(n),e,o;
    for(int i = 0 ; i<n ; i++){
        cin>>a[i];
        if(a[i] & 1){
            cntO++;
            o.push_back(a[i]);
        }
        else{
            cntE++;
            e.push_back(a[i]);
        }
    }

    sort(e.begin(),e.end());
    sort(o.begin(),o.end());

    //Edge Case Even
    if(cntE == n){
        for(int k = 1; k <= n ; k++){
            cout<<0<<' ';
        }
        cout<<endl;
        return;
    }

    //Edge Case Odd
    if(cntO == n){
        for(int k = 1;  k <= n ; k++){
            if(k&1){
                cout<<o.back()<<' ';
            }else{
                cout<<0<<' ';
            }
        }
        cout<<endl;
        return;
    }
    ll score = o.back();

    vector<ll>ans(n+1);

    ans[1] = score;  

    for(int k = 2; k<=n ; k++){
        if(e.size() == 0){
            ans[k] = ans[k-2];
        }else{
            ans[k] = ans[k-1] + e.back();
            e.pop_back();
        }
    }


    if(accumulate(a.begin(), a.end(), 0LL) % 2 == 0){
        ans[n] = 0;
    }
    for(int i = 1;  i<=n ; i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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