#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
int max_total=-1e9;
int n;

void pqr(int k,vector<int> &p,int total) {
    max_total = max(max_total,total);
    if (k>=n) {
        return;
    }
    pqr(k+1,p,total);
    for (int i=0;i<n;i++) {
        bool valid = false;
        for (int j=0;j<k;j++) {
            if (p[j]==-1) continue;
            if (p[j]==i||abs(i-p[j])==k-j) { //x1-x2==y1-y2 => 對角*+
                valid = true;
                break;
            }
        }
        if (valid) continue;
        p[k] = i;
        pqr(k+1,p,total+v[k][i]);
        p[k] = -1;
    }
}

int main() {
    cin>>n;
    vector<int> p(n);
    v.resize(n,vector<int>(n));
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>v[i][j];
        }
    }
    pqr(0,p,0);
    cout << max_total;
}