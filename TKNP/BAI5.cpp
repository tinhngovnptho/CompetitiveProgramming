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

string s;
ll r, N[3], p[3], countX[3]; // Nb, Ns, Nc, pb, ps, pc, countB, countS, count C

bool canCreatHumburger(ll x, ll r) {
	FOR(i, 0, 2) {
		if (N[i] < countX[i] * x) {
			r -= (countX[i] * x - N[i]) * p[i];
		}
	}
	return r >= 0;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> s;
	FOR(i, 0, 2) cin >> N[i];
	FOR(i, 0, 2) cin >> p[i];
	cin >> r;

	FOR(i, 0, sz(s)-1) {
		if (s[i] == 'B') {
			countX[0]++;
		} else if (s[i] == 'S') {
			countX[1]++;
		} else countX[2]++;
	}

	ll L = 0LL, R = 1e18, result = 0LL;

	while (L <= R) {
		ll mid = (L + R) / 2;
		if (canCreatHumburger(mid, r)) {
			result = mid;
			L = mid + 1;
		} else R = mid - 1;
	}

	cout << result;

	return 0;
}
