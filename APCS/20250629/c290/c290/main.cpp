#include <bits/stdc++.h>


using namespace std;

int main()
{
    int a=0,b=0;
//    ifstream fin("t.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"efe";
    vector<int> vec;

    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
            char tmp=s[i];
            vec.push_back(s[i]-'0');
}
    for(int i=0;i<vec.size();i++){
        //cout<<i<<" ";
        if(i%2==0){
            a+=vec[i];

        }else b+=vec[i];
    }
    int ans=abs(a-b);
//    cout<<a<<b<<endl;
    cout<<ans;
}
