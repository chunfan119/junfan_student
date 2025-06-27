#include <bits/stdc++.h>

using namespace std;
struct input{
    string line;
    int dif;

};
bool compare(const input &a,const input &b){
    return a.dif<b.dif;
}
bool compare2(const input &a,const input &b){
    return a.line<b.line;
}
int main()
{
//    ifstream fin("testt.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"error";
    int n=0;
    cin>>n;
    cin.ignore();
    string ln;
    vector<input> k;
    for(int i=0;i<n;i++){
        getline(cin,ln);

        k.push_back({ln});
        unordered_map<char,int> judge;
        for(int j=0;j<ln.size();j++){
            judge[ln[j]]++;
        }
        k[i].dif=judge.size();

}
    stable_sort(k.begin(),k.end(),compare2);
    stable_sort(k.begin(),k.end(),compare);

    cout<<k[0].line<<endl;
//    for(int i=0;i<k.size();i++){
//        cout<<k[i].line<<endl;
//    }

}
