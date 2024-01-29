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

const int MAXN = 1e6 + 11;

int n, s[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	cin >> n;
	FORE(i, 1, n) {
		int x; cin >> x;
		s[i] = s[i - 1] + x;
	}

	int l = 1, r = n, T = 1e9 + 7;

	while (l < r) {
		int sumL = s[l];
		int sumR = s[n] - s[r - 1];
		int sumMid = s[n] - sumL - sumR;
		int maxSum = max(sumL, max(sumR, sumMid));
		int minSum = min(sumL, min(sumR, sumMid));
		minimize(T, maxSum - minSum);
		if (sumL > sumR) r--;
		else l++;
//		cerr << l << " " << r << "\n";
	}

	cout << T;

	return 0;
}
