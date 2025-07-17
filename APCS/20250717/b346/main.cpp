#include <bits/stdc++.h>
using namespace std;

struct tree_node{
    int data;
    tree_node *left;
    tree_node *right;
};
tree_node *creat_node(int val){
    tree_node *node=new tree_node;
    node->data=val;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
tree_node *insert_node(tree_node *node, int val){
    if(node==nullptr) return creat_node(val);
    if(val<node->data) node->left=insert_node(node->left,val);
    else if(val>node->data) node->right=insert_node(node->right,val);
    return node;
}
void preordered(tree_node *node){
    if(node==nullptr) return;
    cout<<node->data<<" ";
    preordered(node->left);
    preordered(node->right);
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n=0;
    while(cin>>n){
    tree_node *tree=nullptr;vector<int> input;
    for(int i=0;i<n;i++){int x;cin>>x;input.push_back(x);}
    for(int i:input) tree=insert_node(tree,i);
    preordered(tree);
    cout<<endl;
    }
}
