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

const int MAXN = 1e6 + 11;

int n;
long long k, a[MAXN];

void calc(long long &res, long long x) {
	FOR(i, 1, n) {
		int l = lower_bound(a + i + 1, a + n + 1, x - a[i]) - a;
		int r = upper_bound(a + i + 1, a + n + 1, x - a[i]) - a - 1;
//		cerr << l << " " << r << "\n";
		res += r - l + 1;
	}
}

void process(void) {
	cin >> n >> k;
	FORE(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	long long res = 0;
	calc(res, k);
	if (k != 0) calc(res, -k);
	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
