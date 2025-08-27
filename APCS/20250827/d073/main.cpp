#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans; cin>>ans;
    ans=(ans%3==0) ? ans/3:ans/3+1;
    cout<<ans<<endl;
}
