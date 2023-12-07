#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<ll, ll>
#define vt vector
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (ll) (x) * (x)
#define FOR(i, a, b) for (__typeof(a) i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (__typeof(a) i = (b), _a = (a); i >= _a; --i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template<class T> bool umin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll oo  = 1e18;
const int MOD = 1e9 + 7;
const int mxN  = 500 + 11, mxM = 5e4 + 11;
const int mxVal = 1e6 + 11;

struct Data {
	int w, v, num;
} a[mxN];

ll dp[mxN][mxM], val[mxN][mxM];
int n, m, cnt[mxN];

signed main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	file("");
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i].w >> a[i].v >> a[i].num;
	}
	memset(dp[0], 0, sizeof dp[0]);
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			FOR(k, 0, min(a[i].num, (int)j/a[i].w)) {
				if (dp[i][j] < dp[i-1][j-a[i].w*k] + a[i].v*k) {
					dp[i][j] = dp[i-1][j-a[i].w*k] + a[i].v*k;
					val[i][j] = k;
				}
			}
		}
	}
	cout << dp[n][m] << "\n";
	FORD(i, n, 1) {
		cnt[i] = val[i][m];
		m -= val[i][m] * a[i].w;
	}
	FOR(i, 1, n) cout << cnt[i] << "\n";
}


/**-----------------------------------------------
---------------Author: tinhnopro------------------
---------------While (!Die) Code(); <3------------
-----------------------------------------------**/
