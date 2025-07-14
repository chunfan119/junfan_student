#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    queue<int> q;
    int N=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int k=0;
        cin>>k;
        if(k==1){
            int x=0;
            cin>>x;
            q.push(x);
        }else if(k==2){
            if(q.empty()) cout<<-1<<endl;
            else cout<<q.front()<<endl;
        }else if(k==3&&!q.empty()) q.pop();
    }
}
