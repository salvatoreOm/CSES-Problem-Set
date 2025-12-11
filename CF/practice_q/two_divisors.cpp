#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*
    Two Divisors CF


    How & Why?
    a,b, b > a and a == 1

    //Don't try to use your own test cases
    (a,b) = (4,12)

    x = p1*p2*p3*p4 ->Case 1
    another variation of x = p1*p1*p2*p2*p3*p4 -> Case 2
    a -> second largest divisor and b-> largest divisors
    b = (x/p1) = p2*p3*p4
    a = (x/p2) = p1*p3*p4

    LCM(a,b) -> (p1*p2*p3*p4)
    LCM(a,b) -> x

    Case 2:
    b -> (x/p1)             = p1*p2^2*p3*p4
    a -> (x/p1^2)               = p2^2*p3*p4

    LCM(a,b) = p1*p2^2*p3*p4

    b/a = p1 -> b = a*p1
    x = b^2/a; Case 2
*/



















void solve(){
    ll a, b;
    cin >> a >> b;

    if(b%a == 0){
        cout<<(b*b)/a<<endl;
    }else{
        cout<<lcm(a,b)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
