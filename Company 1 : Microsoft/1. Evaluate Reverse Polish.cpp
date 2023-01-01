#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+") {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int res = op1 + op2;
            s.push(res);
        }
        else if (tokens[i] == "-") {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int res = op1 - op2;
            s.push(res);
        }
        else if (tokens[i] == "*") {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int res = op1 * op2;
            s.push(res);
        }
        else if (tokens[i] == "/") {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int res = op1 / op2;
            s.push(res);
        }
        else {
            s.push(stoi(tokens[i]));
        }
    }
    return s.top();
}