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

#define NAME	""

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randInt(ll l, ll r) {
	return l + rng() * 1LL * rng() % (r - l + 1);
}

void gen(void) {
	ofstream inp(NAME ".inp");



        inp.close();
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	srand(time(NULL));

	FOR(i, 1, 100) {
		gen();
		system(NAME ".exe");
		system(NAME "_brute.exe");
		if (system("fc " NAME ".out " NAME ".ans") != 0) {
			return 0;
		}
	}

	return 0;
}
