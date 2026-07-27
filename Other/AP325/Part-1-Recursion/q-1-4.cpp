#include <iostream>
#include <vector>
typedef long long LL;
using namespace std;
int n;
long long ans=0;
vector<int> v;
vector<long long>S_v,S_vm;
int cut(int l,int r,int k) {
    if (r-l<=1||k==0) return 0;
    long long total_w = S_v[r]-S_v[l-1];
    long long total_m = S_vm[r]-S_vm[l-1];
    long long center = total_m/total_w;//物理 - 總重/總力矩 = 重心

    LL m = -1;
    LL min_cost = -1;

    // 測試候選人: center 和 center + 1
    for (LL m_candidate = center; m_candidate <= center + 1; m_candidate++) {
        if (m_candidate <= l || m_candidate >= r) continue;
        LL current_cost = abs(total_m - m_candidate * total_w);
        if (m == -1 || current_cost < min_cost) {
            min_cost = current_cost;
            m = m_candidate;
        }
    }

    ans+=v[m];
    cut(l,m-1,k-1);
    cut(m+1,r,k-1);
    return 0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int k;
    cin>>n>>k;
    v.resize(n+1);
    S_v.resize(n+1);
    S_vm.resize(n+1);
    S_v[0]=0;
    v[0]=0;
    S_vm[0]=0;
    for (int i=1;i<=n;i++) {
        cin>>v[i];
        S_v[i] = S_v[i-1]+v[i]; // 前綴和, i1 -> i2的總和為 s[i2]-s[i1]
        S_vm[i] = S_vm[i-1] + (long long)v[i] * i;
    }
    cut(1,n,k);
    cout << ans;
}