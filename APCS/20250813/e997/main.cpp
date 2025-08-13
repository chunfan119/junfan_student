#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    string line;
    getline(cin,line);
    stringstream in(line);
    vector<string> vec;
    string tmp;
    while(in>>tmp){
        vec.push_back(tmp);
    }
    //for(string s:vec) cout<<s<<" ";
    int n; cin>>n;
    cout<<vec[vec.size()-n]<<endl;
}
