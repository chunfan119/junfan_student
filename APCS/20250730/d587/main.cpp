#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> tot;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        tot.push_back(x);
    }
    sort(tot.begin(),tot.end());
    for(int i:tot) cout<<i<<" ";
}
