#include <bits/stdc++.h>
using namespace std;
#define AND 1
#define OR 2
#define XOR 3
#define NOT 4
#define pb push_back
struct node{
    vector<int> from;
    vector<int> to;
    int out=-1;
    int gate=-1;
};
int level=0;
vector<node> vec;
void show_vec()
{
    cout << "=== vec contents === level="<<level<<endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << "Node " << i
             << " | out: " << vec[i].out
             << " | gate: " << vec[i].gate
             << " | from: ";
        for (size_t j = 0; j < vec[i].from.size(); j++)
        {
            cout << vec[i].from[j];
            if (j + 1 < vec[i].from.size()) cout << ",";
        }
        cout << " | to: ";
        for (size_t j = 0; j < vec[i].to.size(); j++)
        {
            cout << vec[i].to[j];
            if (j + 1 < vec[i].to.size()) cout << ",";
        }
        cout << "\n";
    }
    cout << "====================\n";
}
void simulate(vector<int> start){
    if(start.size()==0) {return;}
    level++;
    vector<int> new_s;
    for(int i=0;i<start.size();i++){
        node vv=vec[start[i]];
        for(int j=0;j<vv.to.size();j++){
            int to=vv.to[j];
            //cout<<i<<" ";
            vec[to].from.pb(start[i]);
            if((vec[to].gate==NOT&&vec[to].from.size()==1)||(vec[to].from.size()==2)){
                new_s.pb(to);
                node p=vec[to];
                int gate=vec[to].gate;
                if(gate==AND){
                    if(vec[p.from[0]].out==1&&vec[p.from[1]].out==1) vec[to].out=1;
                    else vec[to].out=0;
                }else if(gate==OR){
                    if(vec[p.from[0]].out==1||vec[p.from[1]].out==1) vec[to].out=1;
                    else vec[to].out=0;
                }else if(gate==XOR){
                    if (vec[p.from[0]].out != vec[p.from[1]].out) vec[to].out = 1;
                    else vec[to].out = 0;
                }else if(gate==NOT){
                    if (vec[p.from[0]].out == 0) vec[to].out = 1;
                    else vec[to].out = 0;
                }
            }
        }
    }
    //show_vec();
    simulate(new_s);
}

int main(){
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int in,outt,logic,line;
    cin>>in>>logic>>outt>>line;
    vector<int> start;
    for(int i=0;i<in+outt+logic;i++){
        node tmp;
        vec.pb(tmp);
    }
    for(int i=0;i<in;i++){
        int tmp; cin>>tmp;
        vec[i].out=tmp;
        start.pb(i);
    }
    for(int i=in; i<logic+in;i++){
        int input; cin>>input;
        vec[i].gate=input;
    }
    for(int i=0;i<line;i++){
        int a,b; cin>>a>>b;
        vec[a-1].to.pb(b-1);
    }
    simulate(start);
    //cout<<start.size()<<"as";
    cout<<level-1<<endl;
    for(int i=logic+in;i<in+logic+outt;i++){
        cout << vec[vec[i].from[0]].out<< " ";
    }
    cout<<endl;
}
