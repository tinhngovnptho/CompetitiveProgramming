// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

typedef pair<int, int> pii;

unordered_map<int, vector<pii> > cnt;
unordered_map<int, int> ans;

const int MAXN = 1e3 + 11;

int n, m, q, k, a[MAXN][MAXN], dp[MAXN];

bool cmp_id(const pii &a, const pii &b) {
	if (a.se == b.se) {
		return a.fi < b.fi;
	}
	return a.se < b.se;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("robot");
	cin >> n >> m >> q >> k;

	FORE(i, 1, n) FORE(j, 1, m) {
		cin >> a[i][j];
		a[i][j] %= k;
		cnt[a[i][j]].push_back(make_pair(i, j));
	}

	vector<pii> lis;

	for (auto x : cnt) {
		sort(ALL(x.se), cmp_id);
//		fill(dp, dp + sz(x.se), 1);
//		FOR(i, 0, sz(x.se)) FOR(j, 0, i)
//			if (x.se[i].se >= x.se[j].se && x.se[i].fi >= x.se[j].fi) {
//				maximize(dp[i], dp[j] + 1);
//			}
//		ans[x.fi] = *max_element(dp, dp + sz(x.se));
		lis.clear();
		lis.push_back(x.se[0]);
		FOR(i, 1, sz(x.se)) {
			if (x.se[i].se >= lis.back().se && x.se[i].fi >= lis.back().fi) {
				lis.push_back(x.se[i]);
			} else {
				int l = lower_bound(ALL(lis), x.se[i]) - lis.begin();
				lis[l] = x.se[i];
			}
		}
		ans[x.fi] = sz(lis);
	}

	while (q--) {
		int x; cin >> x;
		cout << ans[x] << "\n";
	}

	return 0;
}
