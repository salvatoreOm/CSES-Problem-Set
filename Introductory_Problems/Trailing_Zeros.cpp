#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    /*
        How & Why?
        Honestly, it's 11th grade math trick, but I'll explain in a nutshell.
        Hint is : Simply think how you can have a 0 at the end, only with the help of a number ending by 0? NO
        Rather, think in factors, at bare minimum, you will need, one 2 and one 5, to make sure we start getting 0 ending numbers, so think, how many we have for each number.

        And i think that's a good hint.
    */
    
    
    ll n;
    cin>>n;

    if(n < 5){
        cout<<0<<endl;
        return;
    }
    ll powofFive = 5;
    ll ans = 0;
    while(n/powofFive){
        ans += (n/powofFive);
        powofFive *= 5;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}