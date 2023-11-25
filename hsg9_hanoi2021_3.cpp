#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 15;
char c[N][N];
string  vec[N];
int n, m;

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen("DELROW.INP" , "r" , stdin);
        freopen("DELROW.OUT" , "w" , stdout);
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> c[i][j];
            }
        }
        for(int j = 1; j <= m; j++) {
            for(int i = n; i >= 1; i--) {
                vec[j] += c[i][j];
            }
        }
        int length = 0;
        sort(vec + 1 , vec + m + 1);
        for(int i = 1; i <= m; i++) {
    //        cerr << vec[i] << '\n';
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(vec[i][j] == vec[i + 1][j]) cnt++;
                else break;
            }
            length = max(length , cnt);
        }
        cout << n - length - 1 << '\n';
}
