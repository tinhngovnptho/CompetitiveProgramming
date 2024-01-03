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

set<int> d;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("MM.inp", "r", stdin);
	freopen("MM.out", "w", stdout);

	string s;
	getline(cin, s);

	int res = 0;
	bool check = false;
	FOR(i, 0, s.size()-1) {
		if (isdigit(s[i])) {
			res = res * 10 + (s[i] - '0');
			check = true;
		} else {
			if (check) d.insert(res);
			check = false;
			res = 0;
		}
	}

	if (check) d.insert(res);

	cout << d.size();

	return 0;
}
