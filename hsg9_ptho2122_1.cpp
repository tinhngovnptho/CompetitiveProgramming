#include <bits/stdc++.h>

using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i)
        ans += s[i]-'0';
    cout << ans;
}
