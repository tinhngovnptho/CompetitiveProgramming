#include <bits/stdc++.h>

using namespace std;

int numVote[5001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("VOTE.INP", "r", stdin);
    freopen("VOTE.OUT", "w", stdout);
    int n;
    char x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            numVote[j] += (x == 'X');
        }
    }
    int maxVote = *max_element(numVote + 1, numVote + n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (numVote[i] == maxVote) ans.push_back(i);
    }
    cout << (int) ans.size() << " " << maxVote << "\n";
    for (int i = 0; i < (int) ans.size(); ++i) cout << ans[i] << " ";
}
