#include <bits/stdc++.h>
using namespace std;
struct tree_node{
    int data;
    tree_node *left;
    tree_node *right;
}  ;
tree_node *creat_tree(int val){
    tree_node *node=new tree_node;
    node->data=val;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
tree_node *insert_num(tree_node *tree,int val){
    if(tree==nullptr) return creat_tree(val);
    if(tree->data<val) tree->right=insert_num(tree->right,val);
    else if(tree->data>val) tree->left=insert_num(tree->left,val);
    return tree;
}
void preorderd(tree_node *tree){
    if (tree==nullptr) return;
    cout<<tree->data<<" ";
    preorderd(tree->left);
    preorderd(tree->right);
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int n=0;
    while(cin>>n){
    tree_node *tree=nullptr;

    //cin>>n;
    vector<int> input;
    for(int i=0;i<n;i++){
            int x=0;
            cin>>x;
            input.push_back(x);
            }
    //for(int i:input) cout<<i<<" ";
    for(int i:input){
            tree=insert_num(tree,i);}
    preorderd(tree);
    cout<<endl;
    }
}
