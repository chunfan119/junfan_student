#include <bits/stdc++.h>

using namespace std;

struct judge{
    string lines;
    int sizeo;
};
bool compare (judge &a,judge &b){
    return a.sizeo<b.sizeo;
}
bool compare2 (judge &a,judge &b){
    return a.lines<b.lines;
}

int main()
{
//    ifstream fin("test.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"error";
    int n=0;
    cin>>n;
    cin.ignore();
    string line;
    vector<judge> key;
    for(int i=0;i<n;i++){
        getline(cin,line);
        key.push_back({line,line.size()});
    }

    sort(key.begin(),key.end(),compare2);
    sort(key.begin(),key.end(),compare);

    for(int i=0;i<n;i++){
            for(int j=0;j<key[n-1].sizeo-key[i].sizeo;j++){
                cout<<' ';
            }
        cout<<key[i].lines<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
