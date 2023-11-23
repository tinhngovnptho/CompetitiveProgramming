#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long cnt[5];
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cnt[x % 5]++;
    }
    long long ans = cnt[0]*(cnt[0]-1)*(cnt[0]-2)/6;
    ans += cnt[0]*cnt[1]*cnt[4];
    ans += cnt[0]*cnt[2]*cnt[3];
    ans += cnt[1]*cnt[2]*(cnt[2]-1)/2;
    ans += cnt[1]*(cnt[1]-1)*cnt[3]/2;
    ans += cnt[2]*cnt[4]*(cnt[4]-1)/2;
    ans += cnt[3]*(cnt[3]-1)*cnt[4]/2;
    cout << ans;
}
