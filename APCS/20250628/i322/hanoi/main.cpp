#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        cout << "Move disc 1 from " << from << " to " << to << endl;
        return;
    }
    hanoi(n - 1, from, to, aux);                 // 步驟1：先將 n-1 個移到輔助柱
    cout << "Move disc " << n << " from " << from << " to " << to << endl;  // 步驟2：將第 n 個移到目標柱
    hanoi(n - 1, aux, from, to);                 // 步驟3：將 n-1 個從輔助柱移到目標柱
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');  // 初始將 n 個盤從 A 經由 B 移動到 C
    return 0;
}
