#include <iostream>
#include <set>
using namespace std;
typedef long long LL;

int main() {
    LL n,k;
    cin>>n>>k;
    set s({0});
    LL sum=0;
    LL best=0;
    for (int i=0;i<n;i++) {
        int t;
        cin>>t;
        sum+=t;
        //右減"某一個前綴和" = 區間和, 要找到最合適的區間和 新-舊<=k => -舊 <= k-新 => 舊 >=新-k
        auto it = s.lower_bound(sum-k);
        if (it != s.end()) {
            best = max(best,sum-*it);
        }
        s.insert(sum);
    }
    cout << best;
}