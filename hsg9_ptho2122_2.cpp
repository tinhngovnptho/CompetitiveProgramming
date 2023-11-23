#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n;
int cnt = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i*i <= n; ++i) if (n%i == 0) {
        cnt++;
        while (n%i == 0) n /= i;
    }
    if (n>1) cnt++;
    cout << cnt;
}
