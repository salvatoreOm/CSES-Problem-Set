#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void tower(int n, int A, int B, int C,vector<pair<int,int>>&vp) {
    if (n == 1) {
        vp.push_back({A,C});
        return;
    }

    tower(n - 1, A, C, B,vp);  
    vp.push_back({A,C});
    tower(n - 1, B, A, C,vp);  
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>>vp;
    tower(n, 1, 2, 3,vp);

    int size = vp.size();
    cout<<size<<endl;
    for(auto &p : vp){
        cout<<p.first<<' '<<p.second<<endl;
    }
}

int main() {
    solve();
    return 0;
}
