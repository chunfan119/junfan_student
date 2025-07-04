#include <bits/stdc++.h>

using namespace std;

int main()
{
//    ifstream fin("t.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"adfs";
    int n=0;
    cin>>n;
    vector<int> x(n) ,y(n),c;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<n;i++){
        c.push_back(abs(x[i]-x[i-1])+abs(y[i]-y[i-1]));
    }
    sort(c.begin(),c.end());
    cout<<c[c.size()-1]<<" "<<c[0];


//    cin>>n
//vector x y
//vector c
//for(int...){
//	cin>>x[i]>>y[i]
//}
//
//for(){
//	算低絲特斯abs(x1-x2)+abs(y1-y2)
//	放到 c裡面
//
//}
//
//sort c
//
//cout 第一項 最後一項
}
