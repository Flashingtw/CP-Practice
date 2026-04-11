#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll n,v[25];
int ans=0;
void dfs(double cur,int idx,int cnt){
    if(idx==n) {
        ans = max(ans,cnt);
        return;
    }
    if(cur<0){
        if(v[idx]>abs(cur)){
            dfs(cur+v[idx],idx+1,cnt+1);
        }
        else{
            dfs(cur+v[idx],idx+1,cnt);
        }
        dfs(cur-v[idx],idx+1,cnt);
    }
    else{
        if(v[idx]>cur){
            dfs(cur-v[idx],idx+1,cnt+1);
        }
        else{
            dfs(cur-v[idx],idx+1,cnt);
        }
        dfs(cur+v[idx],idx+1,cnt);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dfs(0.5,0,0);
    cout << ans << '\n';
}