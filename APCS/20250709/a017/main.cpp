#include <iostream>                         // �ޤJ�зǿ�J��X
#include <stack>                            // �ϥ� stack �e��
#include <cctype>                           // �P�_�r������ isdigit() ��
#include <string>                           // �B�z�r��
using namespace std;                        // �ϥμзǩR�W�Ŷ�

// �P�_�B��l���u������
int precedence(char op) {
    if (op == '+' || op == '-') return 1; // �[���u�����Ǭ� 1
    if (op == '*' || op == '/'||op=='%') return 2; // �����u�����Ǭ� 2
    return 0;                             // ��L�^�� 0�]�D�B��l�^
}

// �ھڹB��l�i��p��
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;          // �[�k�B��
    if (op == '-') return a - b;          // ��k�B��
    if (op == '*') return a * b;          // ���k�B��
    if (op == '/') return a / b;          // ���k�B��]���Ҽ{���H 0�^
    if (op == '%') return a % b;          // ���k�B��]���Ҽ{���H 0�^
    return 0;                             // �D�k�B��^�� 0
}

// �D�n���B���޿�禡
int evaluate(string expr) {
    stack<int> values;             // ��ƼƭȰ��|
    stack<char> ops;              // �B��l���|
    int i = 0;                    // �Ω�r�걽�y������
    while (i < expr.length()) {   // ���y��Ӫ�F��
        char ch = expr[i];        // ���o��e�r��

        if (isspace(ch)) {        // �����ť�
            i++;                  // ���ʨ�U�@�Ӧr��
            continue;             // �~��U�@���j��
        }

        if (isdigit(ch)) {        // �B�z�h��ƼƦr
            int val = 0;          // �Ȧs��Ƽƭ�
            while (i < expr.length() && isdigit(expr[i])) { // �Y���s��Ʀr
                val = val * 10 + (expr[i] - '0'); // �զX�����
                i++;              // ���ʯ���
            }
            values.push(val);     // ���J�ƭȰ��|
        }

        else if (ch == '(') {
            ops.push(ch);         // ���A���������J�B��l���|
            i++;                  // ���ʯ���
        }

        else if (ch == ')') {   // �B�z�A��������F��
            while (!ops.empty() && ops.top() != '(') { // �Y�D���A���h�p��
                int b = values.top(); values.pop();    // ���X�k���ƭ�
                int a = values.top(); values.pop();    // ���X�����ƭ�
                char op = ops.top(); ops.pop();        // ���X�B��l
                values.push(applyOp(a, b, op));        // ����B��ñ��J
            }
            ops.pop(); // �������A��
            i++;       // ���ʯ���
        }

        else { // �O�B��l + - * /
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) { // �Y���|���u�����ǰ�
                int b = values.top(); values.pop();      // ���X�k���ƭ�
                int a = values.top(); values.pop();      // ���X�����ƭ�
                char op = ops.top(); ops.pop();          // ���X���|�����B��l
                values.push(applyOp(a, b, op));          // ����B�����^�ƭȰ��|
            }
            ops.push(ch); // �N��e�B��l���J���|
            i++;          // ���ʯ���
        }
    }

    while (!ops.empty()) {         // �B�z�ѤU���B��l
        int b = values.top(); values.pop();       // ���X�k���ƭ�
        int a = values.top(); values.pop();       // ���X�����ƭ�
        char op = ops.top(); ops.pop();           // ���X�B��l
        values.push(applyOp(a, b, op));           // ����p��ñ��J�ƭȰ��|
    }
    return values.top();           // �^�ǳ̲׵��G�]���|���ݪ��ȡ^
}

int main() {
    string line ;
    while(getline(cin,line)){
    //string expr = "2 * ( 3 + 4 ) * 5";              // ���տ�J��F��
    //cout << "��F���G" << expr << endl;           // �L�X��l��F��
    cout << evaluate(line) << endl;
    }
    // �p��æL�X���G
    return 0;                                      // �����{��
}
