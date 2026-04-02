#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<char,char>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    int ans=0;
    for(int i=0;i<n-1;i++){
        if(v[i].second==v[i+1].first) ans++;
    }
    cout << ans;
}