#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int c;
    ll l, r;
};
class SegmentTree {
private:
    int n;
    vector<ll> seg, lazy;

    void build(int idx, int low, int high, const vector<int>& a) {
        if (low == high) {
            seg[idx] = a[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void push(int idx, int low, int high) {
        if (lazy[idx] != 0) {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void rangeUpdate(int idx, int low, int high, int l, int r, ll val) {
        push(idx, low, high);

        if (r < low || high < l) return;

        if (l <= low && high <= r) {
            lazy[idx] += val;
            push(idx, low, high);
            return;
        }

        int mid = (low + high) >> 1;
        rangeUpdate(2 * idx + 1, low, mid, l, r, val);
        rangeUpdate(2 * idx + 2, mid + 1, high, l, r, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll rangeQuery(int idx, int low, int high, int l, int r) {
        push(idx, low, high);

        if (r < low || high < l) return 0;
        if (l <= low && high <= r) return seg[idx];

        int mid = (low + high) >> 1;
        return rangeQuery(2 * idx + 1, low, mid, l, r)
             + rangeQuery(2 * idx + 2, mid + 1, high, l, r);
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(0, 0, n - 1, a);
    }

    void update(int l, int r, ll val) {
        rangeUpdate(0, 0, n - 1, l, r, val);
    }

    ll query(int l, int r) {
        return rangeQuery(0, 0, n - 1, l, r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    if (n <= 1) {
        cout<<0<<endl;
        return;
    }

    vector<Node> v;
    v.push_back({0, 0, (ll)2e9 + 7});

    for (int i = 0; i < n - 1; i++) {
        ll d = x[i + 1] - x[i];
        vector<Node> next_v;
        next_v.reserve(v.size() * 2);

        for (auto& p : v) {
            if (p.l < d) {
                next_v.push_back({p.c, 0, d - p.l});
            }
            ll nl = max(0LL, d - p.r);
            ll nr = d - p.l;
            if (nl < nr) {
                next_v.push_back({p.c + 1, nl, nr});
            }
        }

        sort(next_v.begin(), next_v.end(), [](Node& a, Node& b) {
            if (a.c != b.c) return a.c > b.c;
            return a.l < b.l;
        });

        v.clear();
        for (auto& p : next_v) {
            if (!v.empty() && v.back().c == p.c && p.l <= v.back().r) {
                v.back().r = max(v.back().r, p.r);
            } else {
                v.push_back(p);
            }
        }

        if (v.size() > 30) v.resize(30);
    }

    int ans = 0;
    for (auto& p : v) ans = max(ans, p.c);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}