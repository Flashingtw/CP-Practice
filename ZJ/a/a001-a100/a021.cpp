#include <bits/stdc++.h>
using namespace std;

struct BigInt {
    vector<int> d;
    BigInt(string s) {
        for (int i = s.size() - 1; i >= 0; i--) d.push_back(s[i] - '0');
        if(d.empty()) d.push_back(0);
    }
    BigInt() {}
    
    void trim() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
    }

    bool operator<(const BigInt& b) const {
        if (d.size() != b.d.size()) return d.size() < b.d.size();
        for (int i = d.size() - 1; i >= 0; i--)
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        return false;
    }

    void print(bool negative = false) {
        if (negative && !(d.size() == 1 && d[0] == 0)) cout << "-";
        for (int i = d.size() - 1; i >= 0; i--) cout << d[i];
        cout << endl;
    }
};

BigInt add(BigInt a, BigInt b) {
    BigInt res;
    int carry = 0, n = max(a.d.size(), b.d.size());
    for (int i = 0; i < n || carry; i++) {
        int sum = carry + (i < a.d.size() ? a.d[i] : 0) + (i < b.d.size() ? b.d[i] : 0);
        res.d.push_back(sum % 10);
        carry = sum / 10;
    }
    return res;
}

BigInt basic_sub(BigInt a, BigInt b) {
    BigInt res;
    int borrow = 0;
    for (int i = 0; i < a.d.size(); i++) {
        int diff = a.d[i] - borrow - (i < b.d.size() ? b.d[i] : 0);
        if (diff < 0) { diff += 10; borrow = 1; }
        else borrow = 0;
        res.d.push_back(diff);
    }
    res.trim();
    return res;
}

BigInt mul(BigInt a, BigInt b) {
    BigInt res;
    res.d.assign(a.d.size() + b.d.size(), 0);
    for (int i = 0; i < a.d.size(); i++) {
        for (int j = 0; j < b.d.size(); j++) {
            res.d[i + j] += a.d[i] * b.d[j];
            res.d[i + j + 1] += res.d[i + j] / 10;
            res.d[i + j] %= 10;
        }
    }
    res.trim();
    return res;
}

BigInt div(BigInt a, BigInt b) {
    BigInt res, cur;
    res.d.resize(a.d.size());
    for (int i = a.d.size() - 1; i >= 0; i--) {
        cur.d.insert(cur.d.begin(), a.d[i]);
        cur.trim();
        int x = 0;
        while (!(cur < b)) {
            cur = basic_sub(cur, b);
            x++;
        }
        res.d[i] = x;
    }
    res.trim();
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, op, s2;
    cin >> s1 >> op >> s2;
    BigInt a(s1), b(s2);
    if (op == "+") add(a, b).print();
    else if (op == "-") {
    if (a < b) basic_sub(b, a).print(true);
        else basic_sub(a, b).print();
    }
    else if (op == "*") mul(a, b).print();
    else if (op == "/") div(a, b).print();    
}