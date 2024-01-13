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

const int MAXN = 1e6+11;

int N, L, a[MAXN];

bool check(int h) {
	long long total = 0;
	FORE(i, 1, N) if (a[i] > h) {
		total += a[i] - h;
	}
	return total >= L;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("cau4");
	cin >> N >> L;
	FORE(i, 1, N) cin >> a[i];

	int lo = 0, hi = 1e9+11, ans;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		check(mid) ? ans = mid, lo = mid + 1 : hi = mid - 1;
	}

	cout << ans;

	return 0;
}
