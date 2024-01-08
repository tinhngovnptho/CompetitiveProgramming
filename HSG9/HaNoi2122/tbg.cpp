#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; ++i)
#define FORA(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

int x, y, z;

bool canWatch(long long T) {
	long long loadedMB = T * y;
	FORE(i, 1, z) {
		loadedMB += y;
		if (loadedMB < 1LL*x*i) return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("tbg.inp", "r", stdin);
	freopen("tbg.out", "w", stdout);

	cin >> x >> y >> z;

	long long L = 0, R = 1e18+11, ans = 0;
	while(L <= R) {
		long long mid = (L + R) / 2;
		canWatch(mid) ? ans = mid, R = mid - 1 : L = mid + 1;
	}

	cout << ans;

	return 0;
}
