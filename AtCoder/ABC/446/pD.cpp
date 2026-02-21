#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        int num=v[i];
        mp[v[i]] = mp[v[i]-1]+1;
    }
    int ans=0;
    for(auto& [key,val]:mp){
        ans = max(ans,val);
    }
    cout << ans;
}