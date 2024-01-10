#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

// end of template

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("nvt.inp", "r", stdin);
	freopen("nvt.out", "w", stdout);

	int tests; cin >> tests;
	while(tests--) {
		string coord; cin >> coord;
		assert(coord.size() == 2);
		FORE(i, 'a', 'h') if (i != coord[0]) cout << char(i) << coord[1] << "\n";
		FORE(i, 1, 8) if (i != coord[1] - '0') cout << coord[0] << i << "\n";
	}

	return 0;
}
