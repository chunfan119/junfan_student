#include<bits/stdc++.h>
using namespace std;
int main(){
//    ifstream fin("t.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"asd";
    vector<int> bro ,sis;
    int trd=0;
    int tmp=0;
    cin>>tmp;
    bro.push_back(tmp);
    cin>>trd;
    for(int i=0;i<trd;i++){
        cin>>tmp;
        sis.push_back(tmp);
    }
    for(int i=0;i<trd;i++){
        if(bro[i]==sis[i]){
            if(i==0) bro.push_back(sis[i]);
            else if(sis[i]!=sis[i-1]) bro.push_back(sis[i]);
            else if (sis[i]==sis[i-1]){
                if (sis[i]==0) bro.push_back(5);
                else if (sis[i]==2) bro.push_back(0);
                else if (sis[i]==5) bro.push_back(2);

            }

        }else if((bro[i]==0&&sis[i]==2)||(bro[i]==2&&sis[i]==5)||(bro[i]==5&&sis[i]==0)){
            for (int i:bro) cout<<i<<" ";
            cout<<": Won at round "<<i+1;
            return 0;
        }else{
            for (int i:bro) cout<<i<<" ";
            cout<<": Lost at round "<<i+1;
            return 0;
        }

    }
    bro.pop_back();
    for (int i:bro) cout<<i<<" ";
    cout<<": Drew at round "<<trd;
    return 0;

}

