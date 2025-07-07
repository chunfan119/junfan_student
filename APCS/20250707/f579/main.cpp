#include <bits/stdc++.h>

using namespace std;

int main()
{
//    ifstream fin("t.txt");
//    if (fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"ere";
    int cnt=0;

    int a=0 ,b=0, n=0;

    vector<int> rec;
    cin>>a>>b>>n;
    for (int i=0;i<n;i++){
        int tmp=6648;
        int ac=0,bc=0;
        while(tmp!=0){
            cin>>tmp;
            if(tmp==a)  ac+=1;
            else if(tmp==b)  bc+=1;
            else if(tmp==-a)  ac-=1;
            else if(tmp==-b)  bc-=1;
        }
        if (ac>0&&bc>0) cnt++;
    }
    cout<<cnt ;
}


