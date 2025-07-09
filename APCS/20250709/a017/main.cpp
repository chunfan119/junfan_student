#include <iostream>                         // 引入標準輸入輸出
#include <stack>                            // 使用 stack 容器
#include <cctype>                           // 判斷字元類型 isdigit() 等
#include <string>                           // 處理字串
using namespace std;                        // 使用標準命名空間

// 判斷運算子的優先順序
int precedence(char op) {
    if (op == '+' || op == '-') return 1; // 加減優先順序為 1
    if (op == '*' || op == '/'||op=='%') return 2; // 乘除優先順序為 2
    return 0;                             // 其他回傳 0（非運算子）
}

// 根據運算子進行計算
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;          // 加法運算
    if (op == '-') return a - b;          // 減法運算
    if (op == '*') return a * b;          // 乘法運算
    if (op == '/') return a / b;          // 除法運算（不考慮除以 0）
    if (op == '%') return a % b;          // 除法運算（不考慮除以 0）
    return 0;                             // 非法運算回傳 0
}

// 主要的運算邏輯函式
int evaluate(string expr) {
    stack<int> values;             // 整數數值堆疊
    stack<char> ops;              // 運算子堆疊
    int i = 0;                    // 用於字串掃描的索引
    while (i < expr.length()) {   // 掃描整個表達式
        char ch = expr[i];        // 取得當前字元

        if (isspace(ch)) {        // 忽略空白
            i++;                  // 移動到下一個字元
            continue;             // 繼續下一輪迴圈
        }

        if (isdigit(ch)) {        // 處理多位數數字
            int val = 0;          // 暫存整數數值
            while (i < expr.length() && isdigit(expr[i])) { // 若為連續數字
                val = val * 10 + (expr[i] - '0'); // 組合成整數
                i++;              // 移動索引
            }
            values.push(val);     // 推入數值堆疊
        }

        else if (ch == '(') {
            ops.push(ch);         // 左括號直接推入運算子堆疊
            i++;                  // 移動索引
        }

        else if (ch == ')') {   // 處理括號中的表達式
            while (!ops.empty() && ops.top() != '(') { // 若非左括號則計算
                int b = values.top(); values.pop();    // 取出右側數值
                int a = values.top(); values.pop();    // 取出左側數值
                char op = ops.top(); ops.pop();        // 取出運算子
                values.push(applyOp(a, b, op));        // 執行運算並推入
            }
            ops.pop(); // 移除左括號
            i++;       // 移動索引
        }

        else { // 是運算子 + - * /
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) { // 若堆疊內優先順序高
                int b = values.top(); values.pop();      // 取出右側數值
                int a = values.top(); values.pop();      // 取出左側數值
                char op = ops.top(); ops.pop();          // 取出堆疊頂部運算子
                values.push(applyOp(a, b, op));          // 執行運算後推回數值堆疊
            }
            ops.push(ch); // 將當前運算子推入堆疊
            i++;          // 移動索引
        }
    }

    while (!ops.empty()) {         // 處理剩下的運算子
        int b = values.top(); values.pop();       // 取出右側數值
        int a = values.top(); values.pop();       // 取出左側數值
        char op = ops.top(); ops.pop();           // 取出運算子
        values.push(applyOp(a, b, op));           // 執行計算並推入數值堆疊
    }
    return values.top();           // 回傳最終結果（堆疊頂端的值）
}

int main() {
    string line ;
    while(getline(cin,line)){
    //string expr = "2 * ( 3 + 4 ) * 5";              // 測試輸入表達式
    //cout << "表達式：" << expr << endl;           // 印出原始表達式
    cout << evaluate(line) << endl;
    }
    // 計算並印出結果
    return 0;                                      // 結束程式
}
