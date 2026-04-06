#include <bits/stdc++.h>
using namespace std;

int priority(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/" || op == "%") return 2;
    return 0;
}

long long applyOp(long long a, long long b, string op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    if (op == "%") return a % b;
    return 0;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        stack<long long> values;
        stack<string> ops;

        while (ss >> token) {
            if (isdigit(token[0])) {
                values.push(stoll(token));
            } else if (token == "(") {
                ops.push(token);
            } else if (token == ")") {
                while (!ops.empty() && ops.top() != "(") {
                    long long val2 = values.top(); values.pop();
                    long long val1 = values.top(); values.pop();
                    string op = ops.top(); ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                if (!ops.empty()) ops.pop(); 
            } else {
                while (!ops.empty() && priority(ops.top()) >= priority(token)) {
                    long long val2 = values.top(); values.pop();
                    long long val1 = values.top(); values.pop();
                    string op = ops.top(); ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(token);
            }
        }

        while (!ops.empty()) {
            long long val2 = values.top(); values.pop();
            long long val1 = values.top(); values.pop();
            string op = ops.top(); ops.pop();
            values.push(applyOp(val1, val2, op));
        }

        cout << values.top() << endl;
    }
}