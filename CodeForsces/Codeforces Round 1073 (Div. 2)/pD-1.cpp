#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    while (k--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=0,r=0;
        for (int i=0;i<n;i++) {
            if (s[i]=='(') l++;
            else r++;
        }
        if (l==r) cout << l << "\n";
        else cout << -1 << "\n";
    }
}