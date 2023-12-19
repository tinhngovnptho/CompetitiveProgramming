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

ll L, R, T;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("NVT.inp", "r", stdin);
	freopen("NVT.ans", "w", stdout);

	cin >> L >> R >> T;

	cerr << L << " " << R << " " << T << "\n";

	ll cnt = 0;

	for(ll i = L; i <= R; ++i) if (i < T - i && T - i <= R) {
		cerr << i << " ";
		cnt++;
	}

	cout << cnt;

//	cerr << cnt << "\n";

	return 0;
}
