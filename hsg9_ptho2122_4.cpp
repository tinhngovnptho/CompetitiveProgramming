#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6+11, mxM = 1e4+11;
int firstC[10], cnt[mxN], a[mxM], b[mxM], first[mxN];
int n, m, p, x;

int firstDigt(int x) {
    if (first[x] != -1) return first[x];
    string s = to_string(x);
    return first[x] = s[0] - '0';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(first, -1, sizeof first);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= p; ++i) {
        cin >> x;
        firstC[firstDigt(x)]++;
        cnt[x]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] != b[j]) {
                if (a[i] % 10 == firstDigt(b[j])) {
                    ans += (long long) firstC[b[j] % 10];
                    if (b[j] % 10 == firstDigt(b[j])) ans -= cnt[b[j]];
                    if (firstDigt(a[i]) == b[j] % 10) ans -= cnt[a[i]];
                }
            }
        }
    }
    cout << ans;
}
