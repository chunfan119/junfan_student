#include <bits/stdc++.h>
using namespace std;
vector<long long> seq;
long long idx=0;
long long tot=0;
void dfs(int parent){
    if (idx>=seq.size()) return;
    long long now=seq[idx++];
    if(now==0) return;
    tot+=abs(parent-now);
    //cout<<"tot: "<<tot<<endl;
    int bra;
    if(now%2==0) bra=2;
    else bra=3;
    //cout<<"bra: "<<bra<<endl;
    for(int i=0;i<bra;i++) dfs(now);
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asdf";
    long long x;
    while(cin>>x){
        seq.push_back(x);
    }
    //for(auto i:seq) cout<<i<<" ";
    long long root=seq[0];
    //cout<<"root"<<root<<endl;
    int root_bra= (root % 2 == 0) ? 2 : 3;
    for(int i=0;i<root_bra;i++) dfs(root);
    cout<<tot;
}
//�ҥH�ؾ�() �����X ��X�p�U
//�ؾ�():
//    current = sequence[idx++]
//    if current == 0:
//        return
//    branches = 2 if current%2==0 else 3
//    for each branch:
//        dfs(current)
//
//
//
//
//
//
//
//���U���[���D��, �M���N��O�۾F��Ӽƪ������
//2 6 0 8 14 0 0 0 10 0 4 0 0
//2-6 �B��, 6-0 �B��, 6-8 �B��, 8,14 �B��K�K.-> �H���`�I���D�B��ثe�`�I
//
//�N��O�� �]�� 6 �`�I��,�n�� 2 �`�I�B��,
//�]��  6 �`�I��,�n�� 6 �`�I�B��, �H������
//�ҥH�]�p�a�J�@�ӱa�J�Ѽ� parent ���ƭȨíp���`�X total_diff
//�ҥH �ۮt����� = abs(parent- current)
//�ؾ�+�p��(parent):
//    current = sequence[idx++]
//    if current == 0:
//        return
//    total_diff += abs(parent - current)
//    branches = 2 if current%2==0 else 3
//    for each branch:
//        dfs(current)
//
//�̫�Ҽ{ �Ĥ@�ӼƦr (�̤W������) �O���ιB�⪺,�����n��` �_���ƪ��W�h,�ҥH ��� �ؾ�+�p�⪺���㰰�X���Ӧp�U:
//
//Idx = 0
//long long root = sequence[idx++];
//// �ڸ`�I�S�����`�I�A�ҥH���β֭p�t��
//    int root_branches = (root % 2 == 0) ? 2 : 3;
//    for (int i = 0; i < root_branches; i++) {
//        �ؾ�+�p��(root); //�o�̩I�s���j
//    }
