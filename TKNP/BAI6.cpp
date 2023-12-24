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

const int MAX_N = 1e3+7;

int a[MAX_N], b[MAX_N], c[MAX_N], n;

int Fbinsearch(int l, int r, int x) {
	int result = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (c[mid] > x) {
			result = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return result;
}

int Lbinsearch(int l, int r, int x) {
	int result = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (c[mid] < x) {
			result = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, n) {
		cin >> b[i];
	}
	FOR(i, 1, n) {
		cin >> c[i];
	}

	sort(c+1, c+n+1);
	int cnt = 0;

	FOR(i, 1, n) {
		FOR(j, 1, n) {
			int idx1 = Fbinsearch(1, n, abs(a[i]-b[j]));
			int idx2 = Lbinsearch(1, n, a[i] + b[j]);
			if (idx1 == -1 || idx2 == -1 || idx1 > idx2) continue;
//			cout << idx1 << " " << idx2 << " " << i << " " << j << "\n";
			cnt += idx2 - idx1 + 1;
		}
	}

	cout << cnt;

	return 0;
}
