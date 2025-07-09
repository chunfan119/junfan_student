#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return 1LL * a.second * b.first > 1LL * a.first * b.second; // Á×§K·¸¦ì
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<int> w(n), f(n);
    vector<pair<int, int>> ans(n);

    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    for (int i = 0; i < n; i++) {
        ans[i] = {w[i], f[i]};
    }

    sort(ans.begin(), ans.end(), compare);

    vector<long long> prefix(n);
    prefix[0] = ans[0].first;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + ans[i].first;
    }

    long long tot = 0;
    for (int i = 1; i < n; i++) {
        tot += 1LL * ans[i].second * prefix[i - 1];
    }

    cout << tot;
}
