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
int k;
bool prime[MAXN];

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	prime[0] = prime[1] = 0;
	FORE(i, 2, sqrt(n)) if (prime[i]) FORE(j, i, n / i) prime[i * j] = 0;
}

void process(void) {
	cin >> k;
	sieve(MAXN - 1);
	int x;
	vector<int> v;
	while (cin >> x) {
		if (prime[x]) v.push_back(x);
	}
	sort(ALL(v));
	REP(i, k) cout << v[i] << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("daynt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
