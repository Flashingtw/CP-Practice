#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int num) {
    string s = to_string(num);
    int n = s.length();
    long long sum = 0;
    int temp = num;
    
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }
    
    return sum == num;
}

int main() {
    int n, m;
    cin >> n >> m;
    bool found = false;
    for (int i = n; i <= m; i++) {
        if (isArmstrong(i)) {
            if (found) cout << " ";
            cout << i;
            found = true;
        }
    }
    if (!found) {
        cout << "none";
    }
}