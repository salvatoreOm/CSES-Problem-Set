#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    How & Why?
    we have to figure out ax + by = c have non negative integral solutions or not.   
    We can use the information of c % gcd(a,b) == 0 for integral solutions. But sinces constraints are less we can use brute force.
*/
void solve() {
    int a,b,c;
    cin>>a>>b>>c;

    for(int x = 0 ; a*x <= c ; x++){
        int y = c - (a*x);
        if(y%b == 0){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}