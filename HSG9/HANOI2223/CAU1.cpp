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

string to_str2(int x) {
	string s;
	while (x) {
		s = char(x % 10 + '0') + s;
		x /= 10;
	}
	while (s.size() < 2) s = '0' + s;
	return s;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("TG.inp", "r", stdin);
	freopen("TG.out", "w", stdout);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int h = 8 + n / 60, p = n % 60;
		string time = to_str2(h) + ":" + to_str2(p);
		cout << time << "\n";
	}

	return 0;
}
