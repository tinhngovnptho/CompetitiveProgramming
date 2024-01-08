#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; ++i)
#define FORA(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("arn.inp", "r", stdin);
	freopen("arn.out", "w", stdout);

	string s, x; cin >> s >> x;

	int cnt = 0, idx = 0;
	while(idx < sz(s)) {
		if(s.substr(idx, sz(x)) == x) {
			cnt++;
			idx += sz(x);
		} else idx++;
	}

	cout << cnt;

	return 0;
}
