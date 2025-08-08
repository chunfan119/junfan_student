#include <bits/stdc++.h>
//#define debug
using namespace std;

// �ΨӰl�ܥثeŪ����Ӧr��
int pos = 0;

// ���j�p��C�Ӱ϶����¦⹳���]1�^���ƶq
int count_black_pixels(const string& s, int size) {
    char ch = s[pos++];

    if (ch == '0') {
        // ���հ϶�
        return 0;
    } else if (ch == '1') {
        // ���°϶�
        return size * size;
    } else if (ch == '2') {
        // �V�X�϶��A�����|�Ӱ϶����j�B�z
        int half = size / 2;
        int total = 0;
        total += count_black_pixels(s, half); // ���W
        total += count_black_pixels(s, half); // �k�W
        total += count_black_pixels(s, half); // ���U
        total += count_black_pixels(s, half); // �k�U
        return total;
    }

    return 0; // �z�פW���|��o��
}

int main() {
#ifdef debug
    ifstream f("t.txt");
    if(f) cin.rdbuf(f.rdbuf());
    else cout <<"err";
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif

    string s;
    int n;
    cin >> s >> n;

    pos = 0;
    int result = count_black_pixels(s, n);
    cout << result << endl;

    return 0;
}
