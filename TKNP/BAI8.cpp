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

#define MAX_N	100100

int a[MAX_N], b[MAX_N], n, k;

int countA(int x, int k) {
	FOR(i, 1, n) {
		b[i] = abs(a[i] - x);
	}
	sort(b+1, b+n+1);
	int cnt = 0;
	FOR(i, 1, n) {
		k -= b[i];
		if (k < 0) break;
		cnt++;
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i];
	}

	int L = 0, R = 1e9+11, ans = 0, res = -1e9-11;

	while (L <= R) {
		int mid = (L + R) / 2;
		int cnt = countA(mid, k);
		cerr << cnt << " ";
		if (cnt <= k) {
			if (res < cnt) {
				res = cnt;
				ans = mid;
			} else if (res == cnt) ans = min(ans, mid);
			R = mid - 1;
		} else L = mid + 1;
	}

	cout << res << " " << ans;

	return 0;
}
