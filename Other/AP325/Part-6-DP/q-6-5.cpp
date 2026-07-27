#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int>(n));
    for (int i=0;i<m;i++) for (int j=0;j<n;j++) {
        cin>>v[i][j];
    }
    //窮舉上下
    int ans=0;
    for (int u=0;u<m;u++) {
        vector<int> t(n,0);
        for (int b=u;b<m;b++) {
            for (int j=0;j<n;j++) {
                t[j] += v[b][j];
            }
            int sum=0;
            for (int i=0;i<n;i++) {
                sum = sum>0?sum+t[i]:t[i];
                ans = max(ans,sum);
            }
        }
    }
    cout << ans;
}