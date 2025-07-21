#include <bits/stdc++.h>
using namespace std;
vector<long long> seq;
long long idx=0;
long long tot=0;
void dfs(int parent){
    if (idx>=seq.size()) return;
    long long now=seq[idx++];
    if(now==0) return;
    tot+=abs(parent-now);
    //cout<<"tot: "<<tot<<endl;
    int bra;
    if(now%2==0) bra=2;
    else bra=3;
    //cout<<"bra: "<<bra<<endl;
    for(int i=0;i<bra;i++) dfs(now);
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asdf";
    long long x;
    while(cin>>x){
        seq.push_back(x);
    }
    //for(auto i:seq) cout<<i<<" ";
    long long root=seq[0];
    //cout<<"root"<<root<<endl;
    int root_bra= (root % 2 == 0) ? 2 : 3;
    for(int i=0;i<root_bra;i++) dfs(root);
    cout<<tot;
}
//所以建樹() 的偽碼 整合如下
//建樹():
//    current = sequence[idx++]
//    if current == 0:
//        return
//    branches = 2 if current%2==0 else 3
//    for each branch:
//        dfs(current)
//
//
//
//
//
//
//
//接下來觀察題目, 和的意思是相鄰兩個數的絕對值
//2 6 0 8 14 0 0 0 10 0 4 0 0
//2-6 運算, 6-0 運算, 6-8 運算, 8,14 運算…….-> 以父節點為主運算目前節點
//
//意思是當 跑到 6 節點時,要跟 2 節點運算,
//跑到  6 節點時,要跟 6 節點運算, 以此類推
//所以設計家入一個帶入參數 parent 的數值並計算總合 total_diff
//所以 相差絕對值 = abs(parent- current)
//建樹+計算(parent):
//    current = sequence[idx++]
//    if current == 0:
//        return
//    total_diff += abs(parent - current)
//    branches = 2 if current%2==0 else 3
//    for each branch:
//        dfs(current)
//
//最後考慮 第一個數字 (最上面的根) 是不用運算的,但仍要遵循 奇偶數的規則,所以 整個 建樹+計算的完整偽碼應該如下:
//
//Idx = 0
//long long root = sequence[idx++];
//// 根節點沒有父節點，所以不用累計差異
//    int root_branches = (root % 2 == 0) ? 2 : 3;
//    for (int i = 0; i < root_branches; i++) {
//        建樹+計算(root); //這裡呼叫遞迴
//    }
