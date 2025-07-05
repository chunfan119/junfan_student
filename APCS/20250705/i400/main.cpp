#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m=0,n=0;

//    ifstream fin("t.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"fk";

    cin>>m>>n;
    cin.ignore();
    string line;
    vector<vector<int>> key(m);
    vector<char> code;
    vector<char> ans;
    vector<int> key_now;
    for(int i=0;i<m;i++){
        getline(cin,line);
        for(int j:line){
            key[i].push_back(j-'0');
        }
    }
    getline(cin,line);
    for(char c:line){
        code.push_back(c);
    }

    for(int j=m-1;j>=0;j--)
        //for(int j=0;j;j--)
        {
        key_now=key[j];
        for(int i=n-1;i>=0;i--){
            if(key_now[i]==1){
                ans.push_back(code[code.size()-1]);
                code.pop_back();

            }else if(key_now[i]==0){
                ans.insert(ans.begin(),code[code.size()-1]);
                code.pop_back();
            }else cout<<"err";
//        for(char c:ans){
//            cout<<c;
//        }
//        cout<<endl;

        }
        //cout<<endl;
        code=ans;
        int judge=0;
        for (int i:key_now){
            judge+=i;
        }
        int jd=0;
        if(n%2==1) jd=1;


        if(judge %2==1){
            //cout<<"t";
            for(int i =0;i<n/2;i++){
                swap(ans[i],ans[i+n/2+jd]);

            }


        }

        code=ans;
        ans.clear();

    }



//    for (auto j:key){
//        for(int i:j){
//            cout<<i<<" ";
//        }
//        cout<<endl;
//    }

for(char c:code){
            cout<<c;
        }
        cout<<endl;

}
