#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int N = 200001;
int max_rank;
int tree[N];
int get_bit(int x) {
    return x&-x;
}
void update(int idx,int val) {
    for (;idx<=max_rank;idx+=get_bit(idx)) {
        tree[idx] = (tree[idx]+val)%mod;
    }
}
int query(int idx) {
    int sum=0;
    for (;idx>0;idx-=get_bit(idx)) {
        sum = (sum+tree[idx])%mod;
    }
    return sum;
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> val(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        val[i] = v[i];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    max_rank = v.size();
    for (int i=0;i<n;i++) {
        int rank = lower_bound(v.begin(),v.end(),val[i])-v.begin()+1;
        int c = (query(rank-1)%mod)+1;
        update(rank,c);
    }
    cout << query(max_rank);
}