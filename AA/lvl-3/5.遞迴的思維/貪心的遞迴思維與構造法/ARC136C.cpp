#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<long long> a(n);
    for(auto &i:a) cin>>i;
    vector<long long> d(n);
    d[0] = a[0]-a[n-1];
    for(int i=1;i<n;i++) {
        d[i] = a[i]-a[i-1];
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=max(0LL,d[i]);
    }
    ans = max(*max_element(a.begin(),a.end()),ans);
    cout << ans << '\n';
}
/*
到底怎麼證明阿?
複習證明
從操作題裡找 lower bound    
猜出一個可能的答案函數
用「反向操作」去證明能達到這個下界
把「每次操作改變多少」變成一個 invariant / potential 的思考
*/