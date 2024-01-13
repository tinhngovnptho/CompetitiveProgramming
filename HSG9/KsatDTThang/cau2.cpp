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

const int MAX = 3e4 + 11;

int n, total = 0;
bool prime[MAX];
vector<int> v;

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	prime[0] = prime[1] = 0;
	FORE(i, 2, sqrt(n)) if (prime[i]) {
		for (int j = i * i; j <= n; j += i) prime[j] = 0;
	}
	v.clear();
	FORE(i, 2, n) if (prime[i]) v.push_back(i);
}

void processCase1(void) {
	FOR(i, 0, sz(v)) FOR(j, i+1, sz(v)) {
		if (v[i] * v[j] > sqrt(n)) continue;
		total++;
		cout << v[i] * v[j] << "\n";
	}
}

void processCase2(void) {
	FORE(i, 2, 13) if (prime[i]) {
		if (pow(i, 8) <= n) total++;
		else break;
		cout << i << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("cau2");
	cin >> n;

	sieve(MAX-1);
//	FOR(i, 0, sz(v)) cout << v[i] << " ";
	processCase1();
	processCase2();

	cout << total;

	return 0;
}
