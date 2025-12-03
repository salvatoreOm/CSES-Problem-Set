#include<bits/stdc++.h>
using namespace std;

void func(int i,set<string>&st, string & s){
    int n = s.size();

    //base case
    if(i == n){
        st.insert(s);
        return;
    }

    for(int j = i ; j < n ; j++){
        swap(s[i],s[j]);
        func(i+1,st,s);
        swap(s[i],s[j]);
    }
}

void solve(){
    string s; cin>>s;

    int n = s.size();

    set<string>st;
    func(0,st,s);

    int size = st.size();
    cout<<size<<endl;
    for(string str : st){
        cout<<str<<endl;
    }
}

int main(){
    solve();
    return 0;
}