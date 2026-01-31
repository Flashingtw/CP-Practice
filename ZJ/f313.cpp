#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C,k,m;
    cin>>R>>C>>k>>m;
    vector<vector<int>> v(R,vector<int>(C));
    vector<vector<int>> t(R,vector<int>(C));
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin>>v[i][j];
            t[i][j]=v[i][j];
        }
    }
    for (int c=0;c<m;c++) {
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                if (v[i][j]==-1) continue;
                int n = v[i][j]/k;
                if (i>0&&t[i-1][j]!=-1) {
                    t[i-1][j]+=n;
                    t[i][j]-=n;
                }
                if (i<R-1&&t[i+1][j]!=-1) {
                    t[i+1][j]+=n;
                    t[i][j]-=n;
                }
                if (j>0&&t[i][j-1]!=-1) {
                    t[i][j-1]+=n;
                    t[i][j]-=n;
                }
                if (j<C-1&&t[i][j+1]!=-1) {
                    t[i][j+1]+=n;
                    t[i][j]-=n;
                }
            }
        }
        v=t;
    }
    int max_n=0,min_n=INT_MAX;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (v[i][j]==-1) continue;
            max_n = max(v[i][j],max_n);
            min_n = min(v[i][j],min_n);
        }
    }
    cout << min_n << "\n" << max_n;
}