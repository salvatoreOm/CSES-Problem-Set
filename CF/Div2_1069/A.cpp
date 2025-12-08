#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
How and Why?
Set se
*/
void solve() {
    int n;
    cin >> n;
    set<int> st;
    vector<int>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
        st.insert(v[i]);
    }

    while (true) {
        int size = st.size();
        if (st.count(size)) {
            cout<<size<<endl;
            return;
        }
        st.insert(size);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
