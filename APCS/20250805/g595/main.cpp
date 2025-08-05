#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> fence(n);
    for(int i=0;i<n;i++){
        cin>>fence[i];
    }
    int tot=0;
    for(int i=0;i<n;i++){
        if(fence[i]==0){
            if(i==0) tot+=fence[i+1];
            else if(i==n-1) tot+=fence[i-1];
            else tot+=min(fence[i+1],fence[i-1]);
        }
    }
    cout<<tot<<endl;
}
