#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
#define FORA(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long

template <class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template <class T> T abs(const T &a) { return a >= 0 ? a : -a; }

<<<<<<< HEAD
=======
#define MAX_N	10000001

const int MOD = 1e9+7;

int mulDiv[MAX_N];

void add(int &a, const int &b) {
	ll res = a + b;
	if (res >= MOD) res -= MOD;
	a = res;
}

int mul(const int &a, const int &b) {
	return 1LL * a * b % MOD;
}

void Sieve(int n) {
	FOR(i, 0, n) mulDiv[i] = i;

	FOR(i, 2, sqrt(n)) {
		mulDiv[i*i] = mul(mulDiv[i*i], i);
		FOR(j, i+1, n / i) {
			mulDiv[i*j] = mul(mulDiv[i*j], i);
			mulDiv[i*j] = mul(mulDiv[i*j], j);
		}
	}
}
>>>>>>> 13036fa7ea7c8c636312cc92f2af6e9dc10a52ba

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

<<<<<<< HEAD

=======
	int L, R;
	cin >> L >> R;

	Sieve(MAX_N-1);
	int ans = 0;

	FOR(i, L, R) add(ans, mulDiv[i]);

	cout << ans;
>>>>>>> 13036fa7ea7c8c636312cc92f2af6e9dc10a52ba

	return 0;
}
