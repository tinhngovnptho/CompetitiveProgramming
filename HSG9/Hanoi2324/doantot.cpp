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

const int MOD = 1e9 + 7;

void input(void) {
	cin >> n;
	FOR(i, 1, n) {
		cin >> l[i] >> r[i];
	}
}

namespace Sub1 {
	bool check(void) {
		FOR(i, 1, n) if (l[i] != r[i]) return false;
		return true;
	}
	void solve(void) {

	}
}

namespace Sub2 {
	bool check(void) {
		if (n > 1000) return false;
		FOR(i, 1, n) if (r[i] > 1000) return false;
		return true;
	}
	void solve(void) {

	}
}

namespace SubAC {
	void solve(void) {

	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("doantot");

	input();
	if (Sub1::check()) Sub1::solve(), return 0;
	if (Sub2::check()) Sub2::solve(), return 0;
	Sub3::solve(), return 0;

	return 0;
}
