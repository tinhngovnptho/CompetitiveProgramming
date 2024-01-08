#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; ++i)
#define FORA(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("drb.inp", "r", stdin);
	freopen("drb.out", "w", stdout);

	int s1, s2, v1, v2;
	cin >> s1 >> v1 >> s2 >> v2;

	assert(s1 != s2);
	if (v2 == v1) return cout << -1, 0;
	int res = (s1 - s2) / (v2 - v1);

	if (res >= 0) cout << res; else cout << -1;

	return 0;
}
