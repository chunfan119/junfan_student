#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b; cin>>a>>b;
    int ans=(a<b) ? b-a:99-a+b+1;
    cout<<ans;
}
