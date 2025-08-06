#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define debug

int main() {
    #ifdef debug
    ifstream f("t.txt");
    if(f) cin.rdbuf(f.rdbuf());
    else cout <<"err";
    #else
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif // debug

    int n;
    ll L;
    cin >> n >> L;

    vector<ll> cuts(n + 1);
    for (int i = 0; i < n; ++i) {
        ll x;
        int idx;
        cin >> x >> idx;
        cuts[idx] = x;
    }

    set<ll> positions = {0, L};
    #ifdef debug
    cout<<"positions=" ;for(auto &ap:positions) cout << ap <<" "; cout<<endl;
    #endif // debug
    ll total_cost = 0;

    for (int i = 1; i <= n; ++i) {
        ll x = cuts[i];

        auto it = positions.upper_bound(x);
        ll right = *it;
        ll left = *(--it);

        total_cost += right - left;
        positions.insert(x);

        #ifdef debug
        cout <<"x["<<i<<"]:"<<x<<" find: L="<<left  <<",R="<<right<<" ,total="<<total_cost<< " "<<endl;
        cout <<"cut["<<i<<"]:"<<x<<"-->";
        for(auto &ap:positions) cout << ap <<" ";cout <<endl;
        #endif // debug

    }

    cout << total_cost << '\n';
    return 0;
}
