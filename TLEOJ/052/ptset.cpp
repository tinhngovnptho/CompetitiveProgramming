// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MAXN = 2e3 + 11;

pair<int, int> p[MAXN];
int n;
unordered_map<pair<int, int>, int> dp[MAXN];

void process(void) {
	cin >> n;
	FORE(i, 1, n) cin >> p[i].fi >> p[i].se;
	sort(p + 1, p + n + 1);
	FORE(i, 2, n) {
		FOR(j, 1, i) {
			int c_x = p[i].fi - p[j].fi, c_y = p[i].se - p[j].se;
			pair<int, int> c = make_pair(c_x, c_y);
			if (dp[j].count(c)) {
				maximize(dp[i][c], dp[j][c] + 1);
			} else {
				dp[i][c] = 2;
				dp[j][c] = 1;
			}
		}
	}
	int ans = 0;
	pair<int, int> p_start;
	FORE(i, 1, n) {
		FORA(it, dp[i]) {
			if (maximize(ans, it->se)) {
				p_start = it->fi;
			}
		}
	}
	int start = 0;
	FORE(i, 1, n) {
		bool check = false;
		FORA(it, dp[i]) if (p_start == it->fi) {
			start = i;
			check = true;
			break;
		}
		if (check) break;
	}
	cout << ans << "\n";
	if (ans == 1) {
		cout << p[1].fi << " " << p[1].se << "\n";
		return ;
 	}
	int d = start;
	cout << p[start].fi << " " << p[start].se << "\n";
	FORE(i, start + 1, n) if (p[i].fi - p[d].fi == p_start.fi && p[i].se - p[d].se == p_start.se) {
		cout << p[i].fi << " " << p[i].se << "\n";
		d = i;
	}

}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("ptset");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
