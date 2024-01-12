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
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MAXS = 5000, MAXD = 500;

string dp[MAXS][MAXD];

bool cmp_str(string a, string b) {
	if (a == "") return true;
	if (sz(a) != sz(b)) {
		return sz(a) > sz(b);
	}
	return a > b;
}

void update(string &a,string b) {
	if (b == "0") return;
	if (cmp_str(a, b)) a = b;
}

string to_str(int a) {
	string res;
	while(a) {
		res = char(a % 10 + '0') + res;
		a /= 10;
	}
	return res;
}

int sumDigt(int a) {
	int res = 0;
	while(a) {
		res += a % 10;
		a /= 10;

	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("findnum");
	int d, s; cin >> d >> s;

	FORE(i, 0, s) {
		FOR(j, 0, d) dp[i][j] = "";
	}
	FOR(i, 1, d) dp[sumDigt(i)][i] = to_str(i);
	dp[sumDigt(d)][0] = to_str(d);
	FORE(i, 1, s) {
		FOR(j, 0, d) {
			FORE(k, 0, 9) {
				if (i + k <= s) update(dp[i + k][(j * 10 + k) % d], dp[i][j] + char(k + '0'));
				if (i + k == s && (j * 10 + k) % d == 0) cout << i << " " << j  << "\n";
			}
		}
	}

	FORE(i, 1, s) {
		FOR(j, 0, d) cout << i << " " << j << ": " << dp[i][j] << "\n";
	}

	cout << dp[s][0];

	return 0;
}
