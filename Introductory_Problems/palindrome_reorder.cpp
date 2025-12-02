#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;cin>>s;

    unordered_map<char,int> mp;
    for(char c : s) mp[c]++;

    int oddCnt = 0;
    char oddChar = 0;
    for(auto &p : mp){
        if(p.second % 2 == 1){
            oddCnt++;
            oddChar = p.first;
        }
        if(oddCnt > 1){
            cout<<"NO SOLUTION\n";
            return;
        }
    }

    // Build palindrome
    string half = "", middle = "";

    for(auto &p : mp){
        char c = p.first;
        int f = p.second;

        if(f % 2 == 1){
            middle = string(f, c); 
        } else {
            half += string(f / 2, c);
        }
    }

    if(oddCnt == 1){
        int f = mp[oddChar];
        int halfCnt = f / 2;
        
        middle = string(1, oddChar);
        half += string(halfCnt, oddChar);
    }

    sort(half.begin(), half.end()); 
    string revHalf = half;
    reverse(revHalf.begin(), revHalf.end());
    cout << half << middle << revHalf << "\n";
}

int main(){
    solve();
    return 0;
}
