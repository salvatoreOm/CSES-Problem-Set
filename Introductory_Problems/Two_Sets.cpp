#include<bits/stdc++.h>
using ll = long long;
using namespace std;

/*
An observation is that, since we know, that the numbers are sorted and continious in nature i.e 1,2,3,4 till n and we know these have special properties like sum n(n+1)/2, so it makes sense to do the solution greedily, as we will not get stuck to find a smaller number.
because remainder can always be found in the sequence.

Or else we have to do the solution recursively.
*/

void solve(){
    ll n;
    cin >> n;

    ll target = n * (n + 1) / 2;

    if(target & 1){
        cout << "NO\n";
        return;
    }

    target /= 2;
    cout << "YES\n";

    vector<ll> set1;
    ll t = target;

    for(ll i = n; i >= 1; i--){
        if(i <= t){
            set1.push_back(i);
            t -= i;
            if(t == 0){
                break;
            }
        }
    }

    cout << set1.size() << "\n";
    for(ll x : set1) cout << x << " ";
    cout << "\n";

    set<ll> st(set1.begin(), set1.end());
    cout << n - set1.size() << "\n";
    for(ll i = 1; i <= n; i++){
        if(st.count(i) == 0) cout << i << " ";
    }
    cout << "\n";
}

int main(){
    solve();
    return 0;
}
