#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int) (x).size()
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 1e6+11;
int MAX_DIST = 1e6;
int n, k, a[MAXN];

bool check(int x) {
	FOR(i, 1, n) {
		int d = a[i] + x, cnt = 1;
		FOR(j, i+1, n) {
			if (a[j] > d + x) {
				cnt++;
				d = a[j] + x;
			}
		}
		cout << cnt << " ";
		if (i == 1)  {
			if (cnt <= k) return true;
			continue;
		}

		if (d >= MAX_DIST) {
			d -= MAX_DIST;
		} else d = -1e9+7;

		if (d + x < a[1]) {
			d = a[1] + x;
			cnt++;
		}

		FOR(j, 2, i-1) {
			if (a[j] > d + x) {
				cnt++;
				d = a[j] + x;
			}
		}
		cout << cnt << "\n";
		if (cnt <= k) {
//			cout << x << ": " << cnt << " " << i << "\n";
			return true;
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("TPS.inp", "r", stdin);
	freopen("TPS.out", "w", stdout);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	cin >> k;

	sort(a+1, a+n+1);

//	FOR(i, 1, n) cout << a[i] << "\n";

	int L = 0, R = 1e6+11, ans = 0;

	cout << check(13531) << "\n";

//	while (L <= R) {
//		int mid = (L + R) / 2;
//		if (check(mid)) {
//			ans = mid;
//			R = mid - 1;
//		} else L = mid + 1;
//	}
//
//	cout << ans;

	return 0;
}
