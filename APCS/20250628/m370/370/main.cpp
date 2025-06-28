#include <bits/stdc++.h>

using namespace std;

int main()
{
//    ifstream fin("t.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"r";
    int left=0; int right=0;
    int x=0, n=0;
    cin>>x>>n;
    cin.ignore();
    vector<int> food;
    int input;
    for(int i=0;i<n;i++){
        cin>>input;
        food.push_back(input);
    }

    for(int i:food){
        if(i<x) left+=1;
        else if(i>x) right+=1;
    }

    sort(food.begin(),food.end());
    if(left>right){
        cout<<left<<' '<<food[0];
    }else cout<<right<<' '<<food[n-1];



}
