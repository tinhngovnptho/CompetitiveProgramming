#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define vt vector
#define pub push_back
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (x) * (x)
#define FORC(i, a, b, s) for (__typeof(a) i=(a); (s)>0 ? i<=(b) : i>=(b); i+=(s))
#define FOR(i, a, b) FORC(i, a, b, 1)
#define FORD(i, a, b) FORC(i, a, b, -1)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define tinhnopro signed main

template<class T> bool umin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

const ll oo  = 1e18;
const int INF = 2e9 + 1e8 + 1e7;
const int MOD = 1e9 + 7;
const int mxN  = 1e6 + 11;
const string NAME = "GCD";

mt19937_64 rdg(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll low, ll hight) {
        assert(low <= hight);
        return l + rdg() % (hight - low + 1);
}

tinhnopro() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
//        file("KEK");
        int test;
        cin >> test;
        FOR(i, 1, test) {
                ofstream inp((NAME + ".inp").c_str());
                // Gen test

                // End
                inp.close();
                system((NAME + ".exe").c_str());
                system((NAME + "_gen.exe").c_str());
                if (system(("fc" + NAME + ".out" + NAME + "_gen.out").c_str()) != 0) {
                        cout << "WRONG\n";
                        return 0;
                }
                cout << "CORRECT\n";
        }
}
