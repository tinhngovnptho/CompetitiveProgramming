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

#define MAX_N	5050

int n;
ll a[MAX_N], t;
vector<ll> sum;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> t;
	t *= 3;
	FOR(i, 1, n) {
		cin >> a[i];
	}

	FOR(i, 1, n-1) {
		FOR(j, i+1, n) {
			sum.push_back(a[i] + a[j]);
		}
	}

	sort(a+1, a+n+1);

	ll minC = 1e18, ans = -1e18;

	FOR(i, 0, sz(sum)-1) {
		int mi = lower_bound(a+1, a+n+1, t - sum[i]) - a;
		int mx = upper_bound(a+1, a+n+1, t - sum[i]) - a - 1;
		if (abs(sum[i] + a[mi] - t) < minC) {
			minC = abs(sum[i] + a[mi] - t);
			cerr << a[mi] << " " << sum[i] << "\n";
			ans = max(ans, sum[i] + a[mi]);
		}
		if (abs(sum[i] + a[mx] - t) < minC) {
			minC = abs(sum[i] + a[mx] - t);
			cerr << a[mx] << " " << sum[i] << "\n";
			ans = max(ans, sum[i] + a[mx]);
		}
	}

	cout << ans;

	return 0;
}
