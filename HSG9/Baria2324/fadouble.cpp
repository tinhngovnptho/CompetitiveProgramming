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

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("fadouble");
	int n; cin >> n;

	ll ans = 0;

	for (ll idx = 1, d = 1; idx <= n; idx += 2, d *= idx) {
//		cerr << d << " ";
		ans += d;
	}

	for (ll idx = 2, d = 2; idx <= n; idx += 2, d *= idx) {
//		cerr << d << " ";
		ans -= d;
	}

	cout << ans;


	return 0;
}
