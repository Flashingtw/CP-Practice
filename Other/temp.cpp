#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    for(int i=0;i<26;i++){
        int a;
        cin>>a;
        a--;
        s.push_back('a'+a);
    }
    cout << s << '\n';
}