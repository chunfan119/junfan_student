#include <bits/stdc++.h>

using namespace std;

int main()
{

    int b1=0;
    int s1=0;
//    ifstream fin("t.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"err";
    int num;
    cin>>num;
    int tmp;
    vector<int> scores;
    for(int i=0;i<num;i++){
        cin>>tmp;
        scores.push_back(tmp);
    }


    stable_sort(scores.begin(),scores.end());
    for(int i:scores){
        cout<<i<<" ";

    }
    cout<<endl;




    for(int i=0;i<num;i++){
        if(scores[i]<60){
            b1=scores[i];
        }

    }
    if (scores[0]>=60){
            cout<<"best case"<<endl;

        }else cout<<b1<<endl;
    for(int i=0;i<num;i++){
        if(scores[num-i-1]>59){
            s1=scores[num-i-1];
        }

    }

    if (scores[num-1]<60){
            cout<<"worst case"<<endl;

        }else cout<<s1<<endl;
}
