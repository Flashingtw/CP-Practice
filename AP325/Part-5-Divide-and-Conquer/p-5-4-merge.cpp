#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> v;
vector<int> t;

LL inv(int le,int ri) {
    if (le+1>=ri) return 0;//定義遞迴終止
    int mid = (le+ri)/2;
    LL w = inv(le,mid)+inv(mid,ri) , cross=0;//遞

    t.clear();
    int j = mid;
    for (int i=le;i<mid;i++) {
        while (j<ri&&v[j]<v[i]) {
            t.push_back(v[j++]);
        }
        t.push_back(v[i]);
        cross += j-mid;//j放進去代表前面比較大
    }
    //排序+算cross
    //回寫
    for (int k=le;k<j;k++) {
        v[k] = t[k-le];
    }
    return w+cross;
}


int main() {
    int n;
    cin>>n;
    v.resize(n);
    for (int i=0;i<n;i++) cin>>v[i];
    cout << inv(0,n);
}