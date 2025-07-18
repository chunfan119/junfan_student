#include <bits/stdc++.h>
using namespace std;
int main()
{
   // vector<int> tot;
   ifstream f("t.txt");
   if(f) cin.rdbuf(f.rdbuf());
    else cout<<"as";
    int bigtot=0;
    int big1A=0 ,big1B=0;
    int big2tot=0;
    int big2A=0, big2B=0;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int A;cin>>A;
        int B;cin>>B;
        int tot=A*A+B*B;
        if (tot>bigtot) {
            big2tot=bigtot;
            bigtot=tot;
            big2A=big1A;
            big2B=big1B;
            big1A=A;
            big1B=B;
            //cout<<bigtot;
        }
        else if (big2tot<tot&&tot<bigtot) {
            big2tot=tot;
            big2A=A;
            big2B=B;
        }

    }
    cout<<big2A<<" "<<big2B;
}
