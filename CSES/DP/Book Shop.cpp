#include <bits/stdc++.h>
using namespace std;
struct book{
    int price,page;
};
int main(){
    int n,x;
    cin>>n>>x;
    vector<book> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].price;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].page;
    }
    vector<int> dp(x+1,0);
    for(int i = 0; i < n; i++) {
        int price = v[i].price;
        int page = v[i].page;
        for(int j = x; j >= price; j--) {
            dp[j] = max(dp[j], dp[j - price] + page);
        }
    }
    cout << dp[x];
}