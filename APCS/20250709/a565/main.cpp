#include <bits/stdc++.h>

using namespace std;

int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"aa";
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n=0;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string line;
        getline(cin,line);
        int cnt=0;
        int hp=0;
       // stack<int> s;
        vector<char> vec(line.begin(),line.end());
        for(char c:vec){
            if(c=='.' ) continue;
            if (c=='p') hp++;//s.push(1);
            //else if(c=='q'&&(!s.empty())){
           else if(c=='q'&&(hp>0)){
               // s.pop();
                hp--;
                cnt+=1;
            }
        }
        cout<<cnt<<endl;
    }
}
