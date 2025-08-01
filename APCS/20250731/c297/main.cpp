#include <bits/stdc++.h>
using namespace std;
int hit(string in){
    if(in=="1B") return 1;
    else if(in=="2B") return 2;
    else if(in=="3B") return 3;
    else if(in=="HR") return 4;
    else return 0;
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as ";
    vector<vector<string>>action(9);
    for(int i=0;i<9;i++){
        int n;cin>>n;
        for(int j=0;j<n;j++){
            string x; cin>>x;
            action[i].push_back(x);
        }
    }
    vector<bool> base(3,false);

    int tot; cin>>tot;
    int cnt=0;
    int score =0;
    int round=0;
    int out=0;
    while(cnt<tot){
        for(int i=0;i<9;i++){
            if(cnt>=tot) break;
            int jud=hit(action[i][round]);
            if(jud==0) {
                    out++;cnt++;
                    if(out%3==0) {base.clear();base.resize(3,false);out=0;}
                    }
            else if(jud==1||jud==2||jud==3||jud==4) {
                    vector<bool> tmp(3, false);
                    for(int j=2;j>=0;j--){
                            if(base[j]){
                                int newPos=j+jud;
                                if(newPos>=3) score++;
                                else tmp[newPos]=true;
                            }
                    }
                    if(jud==4){
                        score++;
                    }else{
                         tmp[-1+jud]=true;
                    }
                    base=tmp;
            }

        }
        round++;
    }
    cout<<score<<endl;
//    for(auto i:action){
//        for(string k: i) {
//            cout<<k<<" ";
//        }
//        cout<<endl;
//    }

}
