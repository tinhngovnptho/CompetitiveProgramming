#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long

using namespace std;

template <class X, class Y> bool maximize(X &a, const Y &b) {
	return a < b ? a = b, 1 : 0;
}

template <class X, class Y> bool minimize(X &a, const Y &b) {
	return a > b ? a = b, 1 : 0;
}

#define MAX_N	100100
#define MAX_M	7

int a[MAX_N], s[MAX_M], n, m;
ll p, c, dp[MAX_N][(1<<MAX_M)];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> m >> p >> c;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 0, m-1) cin >> s[i];

	sort(a+1, a+n+1);
	memset(dp[0], -0x3f, sizeof(dp[0]));

	FOR(i, 1, n) {
		FOR(mask, 0, (1<<m)-1) {
			dp[i][mask] = dp[i-1][mask];
			FOR(j, 0, m-1) if
			 ((mask >> j & 1) && i >= s[j]) {
				ll profit = p - c * sqr(a[i] - a[i - s[j] + 1]);
				maximize(dp[i][mask], dp[i-s[j]][mask ^ (1 << j)] + profit);
				maximize(dp[i][mask], dp[i-s[j]][mask] + profit);
			}
		}
	}

	cout << dp[n][(1 << m)-1];

	return 0;
}

