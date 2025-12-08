#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    string s,t;
    cin>>s>>t;

    map<char,int>mpS,mpT;
    for(char c : s)mpS[c]++;
    for(char c : t)mpT[c]++;

    for(auto &[ch,f] : mpS){
        if(mpT[ch] < f){
            cout<<"Impossible"<<endl;
            return;
        }
    }

    string res = "";
    int idx = 0;
    for(int i = 0; i < 26 ; i++){
        char curr = 'a' + i;
        int Tcnt = mpT[curr];
        int Scnt = mpS[curr];
        int extras = Tcnt - Scnt;

        while(idx < s.size()){
            if(s[idx] > curr) break;

            res += s[idx];
            idx++;
        }
        res += string(extras,curr);
    }
    cout<<res<<endl;
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