#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a, b, c, MOD;

ll mul(ll a, ll b) {
    int sign = b < 0 + a < 0;
    a = abs(a); b = abs(b);
    ll res = 0;
    while(b) {
        if (b & 1)
            res = (res + a % MOD) % MOD;
        a = 2 * a % MOD;
        b /= 2;
    }
    if (sign == 1) res = -res;
    return res;
}

int main() {
    freopen("MAXPRO.INP", "r", stdin);
    freopen("MAXPRO.OUT", "w", stdout);
    cin >> a >> b >> c >> MOD;
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (b > 0)
        cout << mul(b, c);
    else
        cout << mul(b, a);
}
