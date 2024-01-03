#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 1e6+11;
int MAX_DIST = 1e6;
int n, k;
ll a[MAXN];

bool check(int x) {
	int cnt1 = 1, d = a[1] + x;
	FOR(i, 2, n) {
		if (a[i] > d + x) {
			cnt1++;
			d = a[i] + x;
		}
	}
	d = a[n] + x;
	int idx = 1, cnt2 = 1;
	while (a[idx] + MAX_DIST <= d + x) idx++;
	if (idx == n) {
		return min(cnt1, cnt2) <= k;
	}
	cnt2++;
	d = a[idx] + x;
	FOR(i, idx+1, n-1) {
		if (a[i] > d + x) {
			cnt2++;
			d = a[i] + x;
		}
	}
	return min(cnt1, cnt2) <= k;
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

	int L = 1, R = 1e6+11, ans = 0;

	while (L <= R) {
		int mid = (L + R) / 2;
		if (check(mid)) {
			ans = mid;
			R = mid - 1;
		} else L = mid + 1;
	}

	cout << ans;

	return 0;
}
