#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n,m;
    cin>>n>>m;
    map<pii,int> mp;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        mp[{u,v}]++;
    }
    cout << 2 << '\n';
    int mx=-1;
    pii idx;
    for(auto [a,b]:mp){
        if(b>mx){
            idx=a;
            mx=b;
        }
    }
    cout << idx.first << ' ' << idx.second << '\n';
}