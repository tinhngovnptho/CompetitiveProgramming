#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        LastA[x % 10]++;
        cntA[x]++;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        string s = to_string(b[i]);
        FirstB[s[0] - '0']++;
        Fa[i] = LastA[b[i]] - cntA[b[i]];
    }
    for (int i = 1; i <= p; ++i) {
        cin >> s;

        FirstC[s[0] - '0']++;
        cnt[ato]
    }
}
