#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2010;
unordered_map<ll,ll> mp;
ll prefix[N];
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        prefix[i]=prefix[i-1]+num;
    }
    //how long
    for(int k=1;k<=n;k++){
        for(int i=1;i+k-1<=n;i++){
            int j = i+k-1;
            ll sum = prefix[j]-prefix[i-1];
            mp[sum]++;
        }
    }
    while(q--){
        ll qs;
        cin>>qs;
        cout << mp[qs] << "\n";
    }
}