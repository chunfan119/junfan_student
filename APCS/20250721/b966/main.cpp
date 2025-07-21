#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> le;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"sd";
    int n;cin>>n;
    le.resize(n);
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        le[i].first=a; le[i].second=b;
    }
    sort(le.begin(),le.end());
    for(int i=0;i<le.size()-1;i++){
        if (le[i].first<=le[i+1].first&&le[i].second>=le[i+1].second){
            le.erase(le.begin()+i+1);
            i--;
            continue;
        }
        if (le[i].second>=le[i+1].first){
            le[i].second=le[i+1].second;
            le.erase(le.begin()+i+1);
            i--;
            continue;
        }
    }
    int tot=0;
    for(int i=0;i<le.size();i++)   tot+= le[i].second-le[i].first;
    cout<<tot<<endl;

}








