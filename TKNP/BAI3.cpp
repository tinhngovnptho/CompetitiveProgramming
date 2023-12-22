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

#define MAX_N	15015

int n, k, a[MAX_N], mx, sum = 0;

bool check(int m) {
	int countBox = 0, usedBox = 0;
	FOR(i, 1, n) {
		usedBox += a[i];
		if (usedBox > m) {
			countBox++;
			usedBox = a[i];
		}
	}
	countBox += usedBox > 0;
	return countBox <= k;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i];
		umax(mx, a[i]);
		sum += a[i];
	}

	int L = mx, R = sum, M = -1;

	while (L <= R) {
		int mid = (L + R) / 2;
		if (check(mid)) {
			M = mid;
			R = mid - 1;
		} else L = mid + 1;
	}

	cout << M;

	return 0;
}
