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
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MAXN = 1e5 + 11;

int n, k, a[MAXN];

namespace Sub1 {
	void solve(void) {
		set<int> s;
		int cnt = 0;
		FORE(i, 1, n) FORE(j, i, n) {
			s.clear();
			FORE(k, i, j) s.insert(a[i]);
			if (s.size() <= k) cnt++;
		}
		cout << cnt;
	}
}

namespace SubAC {

}

void process(void) {
	cin >> n >> k;
	FORE(i, 1, n) cin >> a[i];

	if (n <= 100) Sub1::solve();
	else if (Sub23::check()) Sub23::solve();
	else SubAC::solve();
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
