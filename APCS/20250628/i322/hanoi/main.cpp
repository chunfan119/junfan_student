#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        cout << "Move disc 1 from " << from << " to " << to << endl;
        return;
    }
    hanoi(n - 1, from, to, aux);                 // �B�J1�G���N n-1 �Ӳ��컲�U�W
    cout << "Move disc " << n << " from " << from << " to " << to << endl;  // �B�J2�G�N�� n �Ӳ���ؼЬW
    hanoi(n - 1, aux, from, to);                 // �B�J3�G�N n-1 �ӱq���U�W����ؼЬW
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');  // ��l�N n �ӽL�q A �g�� B ���ʨ� C
    return 0;
}
