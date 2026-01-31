#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9+7;
int main() {
    int n;
    cin>>n;
    map<int,long long> mp;
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        mp[x]++;
    }
    long long ans=1;
    for (auto &i : mp) {
        ans =  (ans*(i.second+1))%P;
    }
    cout << (ans - 1 + P) % P;
}