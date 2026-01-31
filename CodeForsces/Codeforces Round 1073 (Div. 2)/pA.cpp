#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    while (k--) {
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        for (int i=0;i<n;i++) {
            int num;
            cin>>num;
            v.push_back({num,(i&1?0:1)});
        }
        sort(v.begin(),v.end());
        bool check = true;
        for (int i=1;i<n;i++) {
            if (v[i-1].second==v[i].second) {
                check = false;
                break;
            }
        }
        cout << (check?"YES":"NO") << "\n";
    }
}