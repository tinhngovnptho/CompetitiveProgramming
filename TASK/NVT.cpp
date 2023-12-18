#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
#define FORA(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(x) (int) (x).size()
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second

template <class X, class Y> bool umin(X &a, const Y &b) { return  a > b ? a = b, 1 : 0; }
template <class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(T& a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template <class T> T abs(T a) { return a >= 0 ? a : -a; }

#define MAX_N	5050
#define MOD	123456789

int n, a[MAX_N], x;

namespace sub12 {
	vector<ll> A, B;

	void TryA(int i, ll sum) {
		if (sum > x) return;

		if (i > n / 2) A.push_back(sum);
		else {
			TryA(i + 1, sum);
			TryA(i + 1, sum + a[i]);
		}
	}

	void TryB(int i, ll sum) {
		if (sum > x) return;

		if (i > n) B.push_back(sum);
		else {
			TryB(i + 1, sum);
			TryB(i + 1, sum + a[i]);
		}
	}
	void solve() {
		TryA(1, 0);
		TryB(n / 2 + 1, 0);

		sort(all(A), greater<ll>());
		sort(all(B));
		int cnt = 0;
		for (int i = 0, j1 = 0, j2 = 0; i < A.size(); ++i) {
			ll s = x - A[i];
			while (j1 < B.size() && B[j1] < s) ++j1;
			while (j2 < B.size() && B[j2] <= s) ++j2;
			cnt = (cnt + j2 - j1) % MOD;
		}

		cout << cnt;
	}
}

namespace sub3 {
	int dp[MAX_N][MAX_N];

	void solve() {
		memset(dp[0], 0, sizeof(dp[0]));
		dp[0][0] = 1;
		FOR(i, 1, n) {
			FOR(j, 0, n) {
				dp[i][j] = j < i ? dp[i-1][j] : (dp[i-1][j] + dp[i][j-i]) % MOD;
			}
		}

		cout << dp[n][n];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> x;
	FOR(i, 1, n) {
		cin >> a[i];
	}

//	if (n <= 40)
//		sub12::solve();
//	else
		sub3::solve();

	return 0;
}
