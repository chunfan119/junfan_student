#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asdf";
//    string line;
//    getline(cin,line);
    unordered_map<int,int> m;
//    for(int i=0;i<line.size();i++){
//        if(line[i]==' ') continue;
//        int k=line[i]-'0';
//        m[k]++;
//    }
    int x;
    while(cin>>x){
        m[x]++;
    }
    for(auto p:m){
            //cout<<p.first<<" "<<p.second<<endl;
        if(p.second%3==2) {
            cout<<p.first<<endl;
            return 0;
        }
    }

}
