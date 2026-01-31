#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> pos(n+1);
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        pos[x]=i;//x的位置在i
    }
    int ans=1;
    for (int i=1;i<n;i++) {
        if (pos[i+1]<pos[i]) {
            ans++;
        }
    }
    cout << ans;
}