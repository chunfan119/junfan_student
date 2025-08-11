#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"a";
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n; cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    //cout<<"a";
    vector<pair<int,int>> ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int xx=a[i][j];
            int tot=0;
            for(int x=0;x<m;x++){
                for(int y=0;y<n;y++){
                    if(abs(x-i)+abs(y-j)<=xx){
                        tot+=a[x][y];
                    }
                }
            }
            if(tot%10==xx){
                pair<int,int> tmp;
                tmp.first=i;
                tmp.second=j;
                ans.push_back(tmp);
            }

        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }


}
