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

long long S, m, n;

void process(void) {
	cin >> m >> n >> S;
	if (S <= m * (n - 1) + (m - 1)) return void(cout << 1 << "\n");
	for (long long k = 1; k < n; ++k) {
		for (long long d = k; d < m; ++d) {
			long long res = S - d * k * (k - 1) - m * k * d * (d - 1) / 2;
			if (res / (d * k) <= m * (n - 1) + (m - 1)) {
				cout << d * k << "\n";
				return ;
			}
		}
	}
	cout << -1 << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("hcn");
	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
