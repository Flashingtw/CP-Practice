#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
long long bit[MAXN];//前綴和
int n;

int lowbit(int x) {
    return x&-x;
}

void update(int idx, int val) {
    for (;idx<=n;idx+= lowbit(idx)) {
        bit[idx]+=val;
    }
}

long long query(int idx) {
    long long sum = 0;
    for (;idx>0;idx-=lowbit(idx)) {
        sum+=bit[idx];
    }
    return sum;
}
long long query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    int q;
    cin>>n>>q;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        update(i,a[i]);
    }
    while (q--) {
        int type;
        cin>>type;
        if (type==1) {
            int k,u;
            cin>>k>>u;
            int diff = u-a[k];
            update(k,diff);
            a[k] = u;
        }
        else {
            int l,r;
            cin>>l>>r;
            cout << query(l,r) << "\n";
        }
    }
}