#include <bits/stdc++.h>
using namespace std;

// 開啟 debug 模式：會嘗試讀入 t.txt 作為測資
//#define debug
#define F first
#define S second
using pii = pair<int, int>; // 定義 pii 簡化表示 pair<int, int>

int main() {
    #ifdef debug
    ifstream f("t.txt");
    if(f) cin.rdbuf(f.rdbuf());  // 如果可以開檔，將 cin 綁到檔案
    else cout <<"err";           // 開檔失敗輸出錯誤
    #else
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif

    int n;
    cin >> n;  // 輸入 n 個水果
    vector<pii> v(n);  // 每個水果 (x, y)

    for (int i = 0; i < n; ++i)
        cin >> v[i].F >> v[i].S;  // 輸入每個水果的 x, y

    // 對所有水果依據 x 做升序排序，若 x 相同則 y 升序
    sort(v.begin(), v.end());

    #ifdef debug
    for (auto pp : v)
        cout << "fruit: " << pp.F << "," << pp.S << endl;  // 印出排序後的水果
    #endif

    // tmp 儲存 LNDS（Longest Non-Decreasing Subsequence）
    vector<int> tmp;

    for (auto i : v) {
        // 如果 tmp 是空的，或目前的 y（i.S） >= 最後一個元素，代表可以加進序列
        if (tmp.empty() || tmp.back() <= i.S) {
            tmp.push_back(i.S);  // 可以繼續吃這顆水果

            #ifdef debug
            cout << "eat: " << i.F << "," << i.S << endl;
            #endif
        } else {
            // 否則找一個剛好大於 i.S 的位置替換，維持 LNDS 的可能性
            int idx = upper_bound(tmp.begin(), tmp.end(), i.S) - tmp.begin();
            tmp[idx] = i.S;

            #ifdef debug
            cout << "not eat: " << i.F << "," << i.S << " -> replace idx " << idx << endl;
            #endif
        }

        // 除錯：印出目前 tmp 的內容
        #ifdef debug
        for (auto x : tmp)
            cout << x <<" ";
        cout <<endl;
        #endif
    }

    // 最終 tmp 的長度即為最多能吃的水果數量
    cout << tmp.size() << "\n";
    return 0;
}
