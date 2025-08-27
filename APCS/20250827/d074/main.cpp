#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    vector<int> cclass(n);
    for(int i=0;i<n;i++){
        int input ;cin>>input;
        cclass[i]=input;
    }
    sort(cclass.begin(),cclass.end());
    cout<<cclass[n-1];
}
