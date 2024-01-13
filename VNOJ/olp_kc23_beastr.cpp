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

const int MAXN = 1e6+11;
int n, q, cnt[MAXN][26];
string s;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	cin >> n >> q >> s;
	s = " " + s;

	FOR(i, 1, sz(s)) {
		REP(c, 26) cnt[i][c] += cnt[i-1][c];
		cnt[i][s[i] - 'a']++;
	}
	while(q--) {
		int l, r; cin >> l >> r;
		l++; r++;
		int res = 0;
		REP(c, 26) if ((cnt[r][c] - cnt[l-1][c]) & 1) res++;
		cout << res / 2 << "\n";
	}

	return 0;
}
