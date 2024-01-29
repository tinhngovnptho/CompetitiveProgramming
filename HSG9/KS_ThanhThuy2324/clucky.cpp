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

const int MAX = 1e6 + 11;

int n, min_prime[MAX];

void sieve(int n) {
	FORE(i, 2, sqrt(n)) if (min_prime[i] == 0) {
		FORE(j, i, n / i) if (min_prime[i * j] == 0) min_prime[i * j] = i;
    }
    FORE(i, 2, n) if (min_prime[i] == 0) min_prime[i] = i;
}

set<int> factor;

void process(void) {
	cin >> n;
	while (n != 1) {
		if (factor.count(min_prime[n])) {
			factor.erase(factor.find(min_prime[n]));
		} else factor.insert(min_prime[n]);
		n /= min_prime[n];
	}
//	FORA(it, factor) cout << *it << " ";
//	cout << "\n";
	cout << (factor.size() ? "NE" : "DA") << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	sieve(MAX - 1);
	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
