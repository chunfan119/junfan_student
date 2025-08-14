#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    string line; getline(cin,line);
    int l; cin>>l; cin.ignore();
    string key; getline(cin,key);
    unordered_map<string,int> store;
    for(int i=0;i<key.size()-l+1;i++){
        string tmp="";
        for(int j=i;j<i+l;j++){
            tmp+=key[j];
        }
        store[tmp]++;
    }
    vector<char> lvc;
    for(char c:line) lvc.push_back(c);
     int n=lvc.size();
    vector<int> idx(l);
    for(int i=0;i<l;i++) idx[i]=0;
    //for(auto a:store) cout<<a.first<<endl;
    string gather="";
    do{
        gather="";
        for(int i:idx) gather+=lvc[i];
//        for(int i:idx) cout<<i;
//        cout<<endl;
//        cout<<gather<<endl;
        idx[l-1]+=1;
        for(int i=l-1;i>0;i--){
            if(idx[i]>n-1){
                idx[i]=0;
                idx[i-1]+=1;
            }
        }
    }while(store[gather]);
    cout<<gather<<endl;
}
