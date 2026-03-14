#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool solve(){
    int n;
    cin>>n;
    vector<vector<int>> matr(n+1,vector<int>(n+1));
    vector<vector<int>> adj(n+1);
    vector<int> cnt(n+1,-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>matr[i][j];
            if(matr[i][j]) cnt[j]++;
            if(i!=j){
                adj[j].push_back(i);
            }
        }
    }
    vector<pii> ans;
    for(int i=1;i<=n;i++){
        vector<int> chd;
        vector<bool> vis;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            chd.push_back(cnt[j]);
        }
        sort(chd.begin(),chd.end(),greater());
        int ptr=0;
        for(;ptr<chd.size();ptr++){
            
        }
    }

    if(ans.size()!=n-1) return false;
    
    cout << "Yes\n" << ans.size() << '\n';
    for(auto [u,v]:ans){
        cout << u << ' ' << v << '\n';
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        if(!solve()) cout << "No" << ' ';
    }
}