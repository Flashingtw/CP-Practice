#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,char> pic;
const int INF = 1e9+9;
struct ev{
    int x;
    char c;
    int idx;
    bool operator<(const ev &a) const{
        return x<a.x;
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ev> v(n);
    for(int i=0;i<n;i++) cin>>v[i].x,v[i].idx=i;
    for(int i=0;i<n;i++) cin>>v[i].c;
    sort(v.begin(),v.end());
    vector<vector<ev>> st(2);
    vector<int> ans(n); 
    for(int i=0;i<n;i++){
        int l = v[i].x&1;
        if(!st[l].empty()&&st[l].back().c=='R'&&v[i].c=='L'){
            int d = (v[i].x-st[l].back().x)/2;
            ans[st[l].back().idx]=ans[v[i].idx]=d;;
            st[l].pop_back();
        }
        else{
            st[l].push_back(v[i]);
        }
    }
    for(int l=0;l<2;l++){
        int sz = st[l].size();
        //L
        int cntl=0,cntr=0;
        for(int i=0;i+1<sz;i+=2){
            if(st[l][i].c!='L'||st[l][i+1].c!='L') break;
            int d = (st[l][i+1].x+st[l][i].x)/2;
            ans[st[l][i].idx]=ans[st[l][i+1].idx]=d;
            cntl+=2;
        }
        //R
        for(int i=sz-1;i-1>=0;i-=2){
            if(st[l][i].c!='R'||st[l][i-1].c!='R') break;
            int d = m-(st[l][i].x+st[l][i-1].x)/2;
            ans[st[l][i].idx]=ans[st[l][i-1].idx]=d;
            cntr+=2;
        }
        if(sz-(cntl+cntr)>1){
            int d = m+(st[l][cntl].x-st[l][cntl+1].x)/2;
            ans[st[l][cntl].idx]=ans[st[l][cntl+1].idx]=d;
        }
        if(sz!=(cntl+cntr)&&ans[st[l][cntl].idx]==0) ans[st[l][cntl].idx]=-1;
    }
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}