#include <bits/stdc++.h>

using namespace std;

int main()
{

//        ifstream f("t.txt");
//        if(f) cin.rdbuf(f.rdbuf());
//        else cout<<" sd";
        stack<int>  s;

        int n=0;
        cin>>n;
        for(int i=0;i<n;i++){
//            int siz=s.size();
            int k=0,x=0;
            cin>>k;
            if(k==1){
                cin>>x;
                s.push(x);
            }
            else if(k==2){


                if (s.empty()) cout<<"-1"<<endl;
                else cout<<s.top()<<endl;
            }
            else if(k==3&&(!s.empty())) s.pop();

        //cout <<"size: "<<s.size()<<endl;
        }

}
