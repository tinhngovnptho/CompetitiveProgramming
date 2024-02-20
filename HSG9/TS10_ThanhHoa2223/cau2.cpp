#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e6 + 11;

bool prime[MAXN];

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= n; ++i) if (prime[i]) FORE(j, i, n / i) prime[i * j] = 0;
}

int sqr(int x) {
	return x * x;
}

bool isBeauty(int x) {
	int res = 0;
	while (x) {
		res += sqr(x % 10);
		x  /= 10;
	}
	return prime[res];
}

void process(void) {
	int n; cin >> n;
	sieve(1000);
	vector<int> BeautyNum;
	for (int i = 11; ; ++i) {
		if (isBeauty(i)) {
			BeautyNum.push_back(i);
//			cout << i << "\n";
		}
		if (sz(BeautyNum) == n) break;
	}
	cout << BeautyNum.back();
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("cau2");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
