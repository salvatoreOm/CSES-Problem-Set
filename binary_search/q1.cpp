#include <bits/stdc++.h>
using namespace std;
#define ll long long

const double N = 1e-6;

void solve() {
    int n;
    cin >> n;

    double low = 0, high = n;
    double ans = 0;

    while (high - low > N) {
        double mid = low + (high - low) / 2;

        if (mid * mid <= n) {
            ans = mid;   // store valid sqrt candidate
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed << setprecision(6) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}