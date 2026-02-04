#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
LL p;
void rec(vector<LL> &v,size_t i,set<LL> &st,LL prod) {
    if (i>=v.size()) {
        st.insert(prod);
        return;
    }
    rec(v,i+1,st,prod+v[i]);
    rec(v,i+1,st,prod);
}

int main() {
    int n,i;
    cin>>n>>p;
    LL input;
    vector<LL> A,B;
    set<LL> SA,SB;

    for (i=0;i<n/2;i++) {
        cin>>input;
        A.push_back(input);
    }
    for (;i<n;i++) {
        cin>>input;
        B.push_back(input);
    }
    rec(A,0,SA,0);
    rec(B,0,SB,0);
    LL ans =0;
    for (auto num : SA) {
        LL k = p-num;
        auto it = SB.upper_bound(k);
        LL current = num;
        if (it!=SB.begin()) {
            --it;
            current += *it;
        }
        ans = max(current,ans);
    }
    cout << ans;
}