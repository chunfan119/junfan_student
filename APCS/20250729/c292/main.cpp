#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4][2]={
        {0,-1},
        {-1,0},
        {0,1},
        {1,0}
    };
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    vector<vector<int>> vec;
    vector<int> ans;
    int n,d; cin>>n>>d;
    for(int i=0;i<n;i++){
        vector<int>tmp;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            tmp.push_back(x);
        }
        vec.push_back({tmp});
    }
    int idxi= n/2;
    int idxj= n/2;
    cout<<vec[idxi][idxj];
    for (int k=1;k<=n;k++){
        for(int p=0;p<2;p++){
            for(int l=0;l<k;l++){
                int dx=arr[d][0];
                int dy=arr[d][1];
                idxi+=dx;idxj+=dy;
                if(idxi<0||idxj<0||idxi>n-1||idxj>n-1) break;
                cout<<vec[idxi][idxj];
            }
            d++; d%=4;
        }

    }
    cout<<endl;
//    for(auto i:vec){
//        for(int k:i) {
//            cout<<k<<" ";
//        }
//        cout<<endl;
//    }

}
