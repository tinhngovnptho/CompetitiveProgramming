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

int n, a[MAX_N], S;

int Lowbinsearch(int l, int r, int x) {
	int res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] <= x) {
			if (a[mid] == x) {
				res = mid;
			}
			r = mid - 1;
		} else l = mid + 1;
	}
	return res;
}

int Hightbinsearch(int l, int r, int x) {
	int res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] <= x) {
			if (a[mid] == x) {
				res = mid;
			}
			l = mid + 1;
		} else r = mid - 1;
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> S;
	FOR(i, 1, n) {
		cin >> a[i];
	}

	sort(a+1, a+n+1);

	ll cnt = 0;

	FOR(i, 1, n-1) {
		int idx1 = Lowbinsearch(i+1, n, S - a[i]);
		int idx2 = Hightbinsearch(i+1, n, S - a[i]);
		if (idx1 != -1 && idx2 != -1) {
			cnt += idx2 - idx1 + 1;
		}
	}

	cout << cnt;

	return 0;
}
