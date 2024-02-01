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

bool isPalin(string s) {
	REP(i, sz(s) / 2) if (s[i] != s[sz(s) - i - 1]) return false;
	return true;
}

void process(void) {
	string s;
	getline(cin, s);
	stringstream ss(s);
	string word;
	int cnt = 0;
	while (ss >> word) {
		cerr << word << " " << isPalin(word) << "\n";
		if (isPalin(word)) cnt++;
	}

	cout << cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("cword");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
