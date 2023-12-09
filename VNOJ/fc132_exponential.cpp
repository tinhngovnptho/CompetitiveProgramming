#include <bits/stdc++.h>
using namespace std;

#define NAME ""
#define endl '\n'
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sqr(x) (ll) (x) * (x)
#define ALL(s) (s).begin(), (s).end()
#define SZ(s) (int)(s).size()
#define For(i, a, b) for (__typeof(a) i = (a), _b = (b); i < _b; ++i)
#define ForE(i, a, b) for (__typeof(a) i = (a), _b = (b); i <= _b; ++i)
#define ForD(i, b, a) for (__typeof(b) i = (b), _a = (a); i >= _a; --i)

template <class T> bool umin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template <class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll oo = 1e18+11;
const int MOD = 1e9+7;
const int mxN = 2e5+7;
const int mxVal = 1e6+11;

unordered_set <int> pw;

void init() {
	pw.insert(1);
	ForE(i, 2, sqrt(mxN)) {
		int x = i*i;
		while (x <= mxN) {
			pw.insert(x);
			x *= i;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen(NAME ".inp", "r", stdin);
	// freopen(NAME ".out", "w", stdout);
	init();
	int x;
	cin >> x;
	ForD(i, x, 1) {
		if(pw.count(i)) {
			cout << i;
			exit(0);
		}
	}
}

/**-----------------------------------------
---------- Author: tinhnopro ---------------
----------While(!Die) Code();---------------
---------//-------NVT-------//--- /\_/\ ----
-------------------------------- (= ._.) ---
-------------------------------- />WA  \> **/
