#include <bits/stdc++.h>
using namespace std;
#define v2
#ifdef v2
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
   int m,n;cin>>m>>n;
//��J colors[0..n-1]     // �C��ǦC�A�@ n ���C��
    vector<string> col (n);
    for(int i=0;i<n;i++){
        string x; cin>>x;
        col[i]=x;
    }
//�إ� freq_map            // �ΨӬ����C���C�⪺�X�{����
    unordered_map<string,int> freq;
    int bcnt = 0;         // �������R�϶����Ӽ�
// ��l�ơG�N�e m ���C���J freq_map
    for(int i=0;i<m;i++){
        freq[col[i]]++;
    }
    if(freq.size()==m) bcnt++;


//��� i �q 0 �� m-1:
//    freq_map[colors[i]] �ƶq�[ 1

//�p�G freq_map ���j�p == m:    // ��ܳo m ���C�ⳣ���@��
//    beauty_count �[ 1

// �}�l�ưʵ����G�q�� m �Ӧ�m�}�l
    for(int i=m;i<n;i++){
        string out=col[i-m];
        string in=col[i];
        freq[out]-=1;
        if(freq[out]==0) freq.erase(out);
        freq[in]+=1;
        if(freq.size()==m) bcnt++;
    }
//��� i �q m �� n-1:
//    out_color = colors[i - m]    // �n���X�������䪺�C��
//    in_color = colors[i]         // �n�[�J�����k�䪺�C��

    // �q freq_map ���� out_color
//    freq_map[out_color] �ƶq�� 1
//    �p�G freq_map[out_color] == 0:
//        �q freq_map ���� out_color
//
//    // �N in_color �[�J freq_map
//    freq_map[in_color] �ƶq�[ 1

    // �ˬd�ثe�������O�_�� m �ؤ��P�C��
    //    �p�G freq_map ���j�p == m:
    //        beauty_count �[ 1
    //
    //��X beauty_count
    cout<<bcnt<<endl;

    return 0;
}


#else// v1
int main()
{
    ifstream f("t.txt");
    if(f) cin.rdbuf(f.rdbuf());
    else cout<<"asd";
    int n,m; cin>>n>>m;
    vector<int> vec(m);
    for(int i=0;i<m;i++){
        int x;cin>>x;
        vec[i]=x;
    }
    int tot=0;
    for(int i=0;i<m-n;i++){
        unordered_map<int,bool> jud;
        int judd;
        for(int j=0;j<n;j++){
            if(jud[vec[i+j]]==true) break;
            jud[vec[i+j]]=true;
            judd=j;
            cout<<i+j;
        }
        if(judd==n-1) {
                tot++;
        }
    }

    cout<<tot;
}
#endif`
