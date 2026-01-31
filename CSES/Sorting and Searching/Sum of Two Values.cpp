#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    int l=0,r=v.size()-1;
    while (l<r) {
        if (v[l].first+v[r].first==x) {
            cout << v[l].second << " " << v[r].second;
            return 0;
        }
        else if (v[l].first + v[r].first < x ) {
            l++;
        }
        else {
            r--;
        }
    }
    cout << "IMPOSSIBLE";
}