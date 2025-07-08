#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f("t.txt");
    if(f) cin.rdbuf(f.rdbuf());
    else cout<<"as";

    int n=0;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        stack<int> s;
        int jud=0;
        int cnt=0;
        string line;
        getline(cin,line);
        for(char c:line){
            if (c=='(')  s.push(1);
            if(c==')'&&(s.empty()))
                {
                    jud=1;
                     break;
                }
            if(c == ')')
            {

                    s.pop() ;
                    cnt+=1;

            }
        }
      if ((s.empty()) && jud ==0)  cout<<cnt<<endl;
      else cout<<0<<endl;
    }
}
