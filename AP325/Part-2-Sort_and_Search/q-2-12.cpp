#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
    int k,m,n;
    cin>>k>>m>>n;
    vector v(m,vector<LL>(n+1,0));
    LL input;
    for (int i=0;i<m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>input;
            v[i][j] = input;
        }
    }

    LL best=0;
    for (int i=0;i<m;i++) {
        vector<LL> c_sum(n+1,0);
        for (int j=i;j<m;j++){
            for (int c=1;c<=n;c++) c_sum[c] += v[j][c];
            set<LL> s({0});
            LL pre=0;
            for (int c=1;c<=n;c++) {
                pre+=c_sum[c];
                auto it = s.lower_bound(pre-k);
                if (it!=s.end()) best = max(best,pre-*it);
                s.insert(pre);
            }
        }
    }
    cout << best;
}