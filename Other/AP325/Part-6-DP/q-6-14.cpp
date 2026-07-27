#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    for (int i=0;i<n;i++) cin>>p[i];
    vector<int> buy(k+1,-1e9),sell(k+1,0);
    //buy,sell為第k次買賣最高利潤
    for (int i : p) {
        for (int j=1;j<=k;j++) {
            buy[j] = max(buy[j],sell[i-1]-i);//維持原本or買股票(花越少的會比較高)
            sell[j] = max(sell[j],buy[j]+i);//不賣or賣掉(今天是否有買的+數值)
        }
    }
    cout << sell[k];
}