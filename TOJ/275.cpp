// TOJ 275
// 分成小的堆跟大的堆，保持兩邊的個數差異在1以內。
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
multiset<ll> small, big;

void pop_big(){
    ll x = *big.begin();
    small.insert(x);
    big.erase(big.begin());
}

void pop_small(){
    ll x = *small.rbegin();
    big.insert(x);
    small.erase(prev(small.end()));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(6);
    cin >> n;
    for(int i=1,x;i<=n;i++){
        cin >> x;

        if(i == 1 || x < *small.rbegin()) small.insert(x);
        else big.insert(x);

        while(big.size() > i/2) pop_big();
        while(big.size() < i/2) pop_small();

        double ans;
        if(i&1) ans = *small.rbegin();
        else ans = (*small.rbegin() + *big.begin()) * 1.0 / 2;
        cout << ans << '\n';
    }
}