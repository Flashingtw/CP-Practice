#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char grid[4005][4005];
int dp[4005][4005];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    int q;
    cin>>q;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]==grid[i-1][j]&&grid[i][j]==grid[i][j-1]){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            }
            else dp[i][j]=1;
            mp[dp[i][j]]++;
        }
    }

    if(mp.size()==0){
        cout << 0 << '\n' << '\n';
    }
    else{
        cout << mp.size() << '\n';
        ll cur=0;
        vector<int> v;
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            v.push_back(it->second+cur);
            cur+=it->second;
        }
        for(int i=v.size()-1;i>=0;i--){
            cout << v[i] << ' ';
        }
    }
}