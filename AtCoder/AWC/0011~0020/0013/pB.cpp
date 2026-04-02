#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
unordered_map<int,int> mp[N+5];
int main(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp[u][v]++;
        if(mp[v].count(u)) ans++;
    }
    cout << ans;
}