#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<char> v;
    string n;
    cin>>n;
    for (int i=0;i<n.length();i++) {
        if (!v.empty()&&n[i]==v.back()) {
            v.pop_back();
            continue;
        }
        v.push_back(n[i]);
    }
    for (int i=0;i<v.size();i++) {
        cout << v[i];
    }
}