#include <bits/stdc++.h>
using namespace std;

// �}�� debug �Ҧ��G�|����Ū�J t.txt �@������
//#define debug
#define F first
#define S second
using pii = pair<int, int>; // �w�q pii ²�ƪ�� pair<int, int>

int main() {
    #ifdef debug
    ifstream f("t.txt");
    if(f) cin.rdbuf(f.rdbuf());  // �p�G�i�H�}�ɡA�N cin �j���ɮ�
    else cout <<"err";           // �}�ɥ��ѿ�X���~
    #else
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif

    int n;
    cin >> n;  // ��J n �Ӥ��G
    vector<pii> v(n);  // �C�Ӥ��G (x, y)

    for (int i = 0; i < n; ++i)
        cin >> v[i].F >> v[i].S;  // ��J�C�Ӥ��G�� x, y

    // ��Ҧ����G�̾� x ���ɧǱƧǡA�Y x �ۦP�h y �ɧ�
    sort(v.begin(), v.end());

    #ifdef debug
    for (auto pp : v)
        cout << "fruit: " << pp.F << "," << pp.S << endl;  // �L�X�Ƨǫ᪺���G
    #endif

    // tmp �x�s LNDS�]Longest Non-Decreasing Subsequence�^
    vector<int> tmp;

    for (auto i : v) {
        // �p�G tmp �O�Ū��A�Υثe�� y�]i.S�^ >= �̫�@�Ӥ����A�N��i�H�[�i�ǦC
        if (tmp.empty() || tmp.back() <= i.S) {
            tmp.push_back(i.S);  // �i�H�~��Y�o�����G

            #ifdef debug
            cout << "eat: " << i.F << "," << i.S << endl;
            #endif
        } else {
            // �_�h��@�ӭ�n�j�� i.S ����m�����A���� LNDS ���i���
            int idx = upper_bound(tmp.begin(), tmp.end(), i.S) - tmp.begin();
            tmp[idx] = i.S;

            #ifdef debug
            cout << "not eat: " << i.F << "," << i.S << " -> replace idx " << idx << endl;
            #endif
        }

        // �����G�L�X�ثe tmp �����e
        #ifdef debug
        for (auto x : tmp)
            cout << x <<" ";
        cout <<endl;
        #endif
    }

    // �̲� tmp �����קY���̦h��Y�����G�ƶq
    cout << tmp.size() << "\n";
    return 0;
}
