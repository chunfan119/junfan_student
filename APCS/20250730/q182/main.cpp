#include <bits/stdc++.h>
using namespace std;
string act1(string line){
    for(int i=0;i<line.size();i++){
        if(i%2==0){
            swap(line[i],line[i+1]);
        }
    }
    return line;
}
string act2(string line){
    for(int i=0;i<line.size();i++){
        if(i%2==0){
            if(line[i]>line[i+1])swap(line[i],line[i+1]);
        }
    }
    return line;
}
string act3(string line){
    string out="";
    int k=line.size()/2;
    for(int i=0;i<line.size()/2;i++){
        out+=line[i];
        out+=line[i+k];
    }
    return out;
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    string line="apcsntnu";
    getline(cin,line);
    int k=0; cin>>k;
    for(int i=0;i<k;i++){
        int act;cin>>act;
        if(act==0) line=act1(line);
        else if(act==1) line=act2(line);
        else if(act==2) line=act3(line);
    }
    cout<<line;

}
