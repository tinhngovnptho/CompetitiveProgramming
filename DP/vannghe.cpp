#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1001, INF = 2e9 + 11;

int n, m, dp[MAXN];
vector<pair<int, int> > t[MAXN];


void process(void) {
	cin >> n >> m;
	REP(i, m) {
		int l, r, c; cin >> l >> r >> c;
		t[r].push_back(mp(l, c));
	}
	REP(j, n + 1) dp[j] = INF;
	REP(j, sz(t[0])) minimize(dp[0], t[0][j].se);
	FORE(i, 1, n) {
		REP(k, sz(t[i])) {
			if (t[i][k].fi == 0) minimize(dp[i], t[i][k].se);
			FOR(j, max(t[i][k].fi - 1, 0) , i) if (dp[j] != INF) minimize(dp[i], dp[j] + t[i][k].se);
		}
	}
	cout << dp[n];
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("vannghe");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
