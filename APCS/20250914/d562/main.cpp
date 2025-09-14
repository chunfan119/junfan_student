#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if (f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n=0;
    while(cin>>n){
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        while(arr.size()>0){
            for(int i:arr) cout<<i<<" ";
            cout<<endl;
            arr.erase(arr.begin());
            vector<int> tmp(arr.size());
            for(int i=0;i<arr.size();i++){
                tmp[tmp.size()-1-i]=arr[i];
            }
            arr=tmp;
            tmp.clear();
        }
        cout<<endl;
    }
}
