#include <bits/stdc++.h>
using namespace std;
#define v2
#ifdef v2
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
   int m,n;cin>>m>>n;
//輸入 colors[0..n-1]     // 顏色序列，共 n 個顏色
    vector<string> col (n);
    for(int i=0;i<n;i++){
        string x; cin>>x;
        col[i]=x;
    }
//建立 freq_map            // 用來紀錄每種顏色的出現次數
    unordered_map<string,int> freq;
    int bcnt = 0;         // 紀錄美麗區間的個數
// 初始化：將前 m 個顏色放入 freq_map
    for(int i=0;i<m;i++){
        freq[col[i]]++;
    }
    if(freq.size()==m) bcnt++;


//對於 i 從 0 到 m-1:
//    freq_map[colors[i]] 數量加 1

//如果 freq_map 的大小 == m:    // 表示這 m 個顏色都不一樣
//    beauty_count 加 1

// 開始滑動視窗：從第 m 個位置開始
    for(int i=m;i<n;i++){
        string out=col[i-m];
        string in=col[i];
        freq[out]-=1;
        if(freq[out]==0) freq.erase(out);
        freq[in]+=1;
        if(freq.size()==m) bcnt++;
    }
//對於 i 從 m 到 n-1:
//    out_color = colors[i - m]    // 要移出視窗左邊的顏色
//    in_color = colors[i]         // 要加入視窗右邊的顏色

    // 從 freq_map 移除 out_color
//    freq_map[out_color] 數量減 1
//    如果 freq_map[out_color] == 0:
//        從 freq_map 移除 out_color
//
//    // 將 in_color 加入 freq_map
//    freq_map[in_color] 數量加 1

    // 檢查目前視窗內是否有 m 種不同顏色
    //    如果 freq_map 的大小 == m:
    //        beauty_count 加 1
    //
    //輸出 beauty_count
    cout<<bcnt<<endl;

    return 0;
}


#else// v1
int main()
{
    ifstream f("t.txt");
    if(f) cin.rdbuf(f.rdbuf());
    else cout<<"asd";
    int n,m; cin>>n>>m;
    vector<int> vec(m);
    for(int i=0;i<m;i++){
        int x;cin>>x;
        vec[i]=x;
    }
    int tot=0;
    for(int i=0;i<m-n;i++){
        unordered_map<int,bool> jud;
        int judd;
        for(int j=0;j<n;j++){
            if(jud[vec[i+j]]==true) break;
            jud[vec[i+j]]=true;
            judd=j;
            cout<<i+j;
        }
        if(judd==n-1) {
                tot++;
        }
    }

    cout<<tot;
}
#endif`
