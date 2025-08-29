#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int r, c;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct bomp {
    int x, y, t;
};
bool bfs(const vector<vector<int>> a, int l) {
    queue<bomp> qu;
    qu.push({r, c, l});
    int ans = 1;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    visited[r][c] = l+10;
    while (!qu.empty()) {
        bomp now = qu.front();
        qu.pop();
        if (now.t == 0) continue;
        for (int i = 0; i < 4; ++i) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != -1) {
                int next = max(a[nx][ny], now.t - 1);
                if (visited[nx][ny]-10 < next) {
                    if (!visited[nx][ny]) ans++;
                    visited[nx][ny] = next+10;
                    qu.push({nx, ny, next});
                }
            }
        }
    }

    return (ans >= q);
}

int main() {
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == -2) {
                r = i;
                c = j;
            }
        }
    }
    int l = 0, r = n * m;
    int ans = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (bfs(a, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans ;
}
