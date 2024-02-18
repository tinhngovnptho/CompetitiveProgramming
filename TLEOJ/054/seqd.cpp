 #include <bits/stdc++.h>

 using namespace std;

 #define fi first
 #define se second
 #define mp make_pair
 #define sz(s) (int)(s).size()
 #define ALL(v) (v).begin(), (v).end()
 #define FOR(i, a, b) for (int i = (a); i < (b); ++i)
 #define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
 #define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
 #define REP(i, n) for (int i = 0; i < (n); ++i)
 #define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
 #define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

 typedef long long int64;
 typedef unsigned long long uint64;
 typedef __int128_t int128;

 template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
 template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

 // end of template

 const int MAXN = 5e5 + 11;

 int n, k;
 int64 a[MAXN];

 int bad(int x) {
	int lim_low = sqrt(x), lim_hight = lim_low + 1;
	int res = abs(lim_low * lim_low - x);
	minimize(res, abs(lim_hight * lim_hight - x));
	return res;
 }

 void process(void) {
 	cin >> n >> k;
 	FORE(i, 1, n) {
		int x; cin >> x;
		a[i] = a[i - 1] + bad(x);
 	}
 	int64 ans = 1e18 + 11;
 	FORE(i, k, n) minimize(ans, a[i] - a[i - k]);
 	cout << ans;
 }

 int main(void) {
 	cin.tie(0)->sync_with_stdio(0);
 	file("seqd");
 	int t = 1; // cin >> t;
 	while (t--) {
 		process();
 	}
 	return 0;
 }

 // author: tinhnopro
