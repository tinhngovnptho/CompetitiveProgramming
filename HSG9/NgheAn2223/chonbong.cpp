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

const int MAXN = 2e5 + 11;

int n, k, a[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("chonbong");
	cin >> n >> k;
	REP(i, n) {
		int x; cin >> x;
		a[x]++;
	}
	sort(a + 1, a + k + 1, greater<int>());

	int cnt = 0;

	FOR(i, 1, k) {
		int l = 0, r = a[i], res = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] + a[i + 1] - 2 * mid <= a[i + 2]) {
				res = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		cnt += 2 * res;
		a[i + 1] = a[i] + a[i + 1] - 2 * res;
	}

	cout << cnt;

	return 0;
}
