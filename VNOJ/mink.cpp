#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<int, int>
#define vt vector
#define pub push_back
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (x) * (x)
#define reset(f, v) memset(f, v, sizeof f)
#define FORC(i, a, b, s) for (__typeof(a) i = (a), _b = (b); (s)>0 ? i<_b : i>_b; i += (s))
#define FORCE(i, a, b, s) FORC(i, a, (s > 0) ? b+1 : b-1, s)
#define FOR(i, a, b) FORC(i, a, b, 1)
#define FORE(i, a, b) FORCE(i, a, b, 1)
#define FORD(i, b, a) FORC(i, a, b, -1)
#define FORDE(i, b, a) FORCE(i, b, a, -1)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template<class T> bool umin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

const ll oo  = 1e18;
const int INF = 2e9 + 1e8 + 1e7;
const int MOD = 1e9 + 7;
const int mxN  = 17000 + 11;

int seg[4*mxN], a[mxN], n, k;

void build(int id, int l, int r) {
        if (l == r)
                return void(seg[id] = a[l]);
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

int query(int id, int l, int r, int u, int v) {
        if (l > v || r < u)
                return INF;
        if (u <= l && r <= v)
                return seg[id];

        int mid = (l + r) >> 1;
        return min(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
}

void solve() {
        reset(seg, 0);
        reset(a, 0);
        cin >> n >> k;
        FORE(i, 1, n) cin >> a[i];
        build(1, 1, n);
        FORE(i, 1, n - k + 1)
                cout << query(1, 1, n, i, i + k-1) << " ";

        cout << "\n";
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int tests;
        cin >> tests;
        while (tests--) {
                solve();
        }
}
