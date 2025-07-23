
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asdasf";
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<unordered_map<char,int>> mem;
    int m,n ;cin>>m>>n;
    cin.ignore();
    mem.resize(n);
    for(int i=0;i<n;i++){
        string line;
        getline(cin,line);
        for(char c:line){
                mem[i][c]++;
        }
    }
    int cp=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            bool flag=false;
            for(auto k:mem[i]){
                if(mem[j].count(k.first)){
                    flag=true;
                }
            }
            if (flag==true) continue;
            bool flag2=false;
            unordered_map<char,int> tot;
            for(auto p:mem[i])  tot[p.first]++;
            for(auto p:mem[j])  tot[p.first]++;
            for(int i=0;i<m;i++){
                char k;
                k=(i<26) ? 'A'+i:'a'+(i-26);
                if(!tot.count(k)) flag2=true;
            }
            if (flag2==true) continue;
            cp++;
        }
    }
    cout<<cp;
}
