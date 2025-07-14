#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, m = 0;
    while (cin >> n) {
        cin >> m;

        vector<int> food(n + 1, 0);       // 1-based，food[1]~food[n]
        vector<int> prefix(n + 1, 0);     // prefix[0] = 0

        for (int i = 1; i <= n; i++) {
            cin >> food[i];
            prefix[i] = prefix[i - 1] + food[i]; // 計算前綴和
        }

        for (int i = 0; i < m; i++) {
            int fr = 0, ba = 0;
            cin >> fr >> ba;
            cout << prefix[ba] - prefix[fr - 1] << endl; // 區間總和查詢
        }
    }
}
