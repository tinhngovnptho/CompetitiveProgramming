#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, b, a) for (int i = (b); i >= (a); i--)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long

template<class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template<class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template<class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; }

#define MAX_N	1001000

int n;
ll prefix[MAX_N], a[MAX_N];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen("CAU4.inp", "r", stdin);
//	freopen("CAU4.out", "w", stdout);

	cin >> n;
	prefix[0] = 0;
	FOR(i, 1, n) {
		cin >> a[i];
		prefix[i] = prefix[i-1] + a[i];
	}
	sort(prefix, prefix+n+1);

	ll ans = 0LL, cnt = 1LL;
	FOR(i, 1, n) {
//		cout << prefix[i] << " ";
//		if (prefix[i] == 0) ans++;
		if (prefix[i] == prefix[i-1]) cnt++;
		else {
//			cout << cnt << " " << prefix[i-1] << "\n";
			ans += cnt * (cnt - 1) / 2;
			cnt = 1LL;
		}
	}

	ans += cnt * (cnt - 1) / 2;

	cout << ans;
}
