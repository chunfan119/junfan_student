#include <bits/stdc++.h>
using namespace std;
unordered_map<long long,int> mask_count;
long long str_to_mask(const string& s){
    long long mask=0;
    for(char c:s){
        int idx=(c>='A'&&c<='Z') ? c-'A' : c-'a' +26;
        mask |=(1LL<<idx);
    }
    return mask;
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asafasd";
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;cin>>m>>n;
    cin.ignore();
    long long full_mask=(1LL<<m)-1;
   // cout<<full_mask<<" "<<bitset<64>(full_mask)<<endl ;
    for(int i=0;i<n;i++){
        string cp;
        cin>>cp;
        long long mask=str_to_mask(cp);
        mask_count[mask]++;
        //cout<<mask<<endl;
    }
    //for(auto p:mask_count) cout<<p.first<<" "<<p.second<<endl;
    long long ans=0;
    for(auto p:mask_count){
       long long mask=p.first;
        int cnt=p.second;
//    for(const auto& [mask, cnt] : mask_count){
        long long complement=full_mask^mask;
        if(mask_count.count(complement)){
            ans+=1LL*cnt*mask_count[complement];
        }
    }
    ans/=2;
    cout<<ans<<endl;
    return 0;
}
