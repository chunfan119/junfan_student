#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    vector<int> num_in (12);
    vector<int> num_out (12);
    int own=0;
    int cnt=1;
    while(1){
        cin>>own;
        if(own<0) break;
        cout<<"Case "<<cnt<<":"<<endl;
        for(int i=0;i<12;i++) cin>>num_in[i];
        for(int i=0;i<12;i++) cin>>num_out[i];
        for(int i=0;i<12;i++){
            if(own>=num_out[i]){
                cout<<"No problem! :D"<<endl;
                own-=num_out[i];
            }else cout<<"No problem. :("<<endl;
            own+=num_in[i];
        }
        cnt++;
    }
}
