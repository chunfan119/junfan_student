#include <bits/stdc++.h>
//#define debug
using namespace std;

// 用來追蹤目前讀到哪個字元
int pos = 0;

// 遞迴計算每個區塊中黑色像素（1）的數量
int count_black_pixels(const string& s, int size) {
    char ch = s[pos++];

    if (ch == '0') {
        // 全白區塊
        return 0;
    } else if (ch == '1') {
        // 全黑區塊
        return size * size;
    } else if (ch == '2') {
        // 混合區塊，分為四個區塊遞迴處理
        int half = size / 2;
        int total = 0;
        total += count_black_pixels(s, half); // 左上
        total += count_black_pixels(s, half); // 右上
        total += count_black_pixels(s, half); // 左下
        total += count_black_pixels(s, half); // 右下
        return total;
    }

    return 0; // 理論上不會到這裡
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
