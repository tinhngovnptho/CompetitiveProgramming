#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mxN = 5011;
int h[mxN][mxN], c[mxN][mxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ITABE.INP", "r", stdin);
    freopen("ITABLE.OUT", "w", stdout);
    int n, q;
    cin >> n >> q;
    while (q--) {
        int k, rc, x, y;
        cin >> k >> rc >> x >> y;
        if (k == 1) {
            h[rc][x]++;
            h[rc][y+2]++;
            if ((y - x + 1) % 2 == 1) {
                h[rc][x + (y - x + 1) / 2 + 1] -= 2;
            }
            else {
                h[rc][x + (y - x + 1) / 2]--;
                h[rc][x + (y - x + 1) / 2 + 1]--;
            }
        }
        else {
            c[x][rc]++;
            c[y+2][rc]++;
            if ((y - x + 1) % 2 == 1) {
                c[x + (y - x + 1) / 2 + 1][rc] -= 2;
            }
            else {
                c[x + (y - x + 1) / 2][rc]--;
                c[x + (y - x + 1) / 2 + 1][rc]--;
            }
        }
    }
    for (int i = 1; i <= n + 2; ++i) {
        for (int j = 1; j <= n + 2; ++j) {
            h[i][j] += h[i][j-1];
            c[i][j] += c[i-1][j];
        }
    }
    for (int i = 1; i <= n + 2; ++i) {
        for (int j = 1; j <= n + 2; ++j) {
            h[i][j] += h[i][j-1];
            c[i][j] += c[i-1][j];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int u, v;
        cin >> u >> v;
        cout << h[u][v] + c[u][v] << "\n";
    }
    return 0;
}
