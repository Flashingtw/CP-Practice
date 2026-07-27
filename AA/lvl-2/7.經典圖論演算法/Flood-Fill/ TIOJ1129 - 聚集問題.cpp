#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool chk(pii a,pii b,ll C){
    auto [ax,ay] = a;
    auto [bx,by] = b;
    int dx = ax-bx;
    int dy = ay-by;
    return (dx*dx)+(dy*dy)<=C*C;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll A,B,C;
    while(cin>>A>>B>>C){
        vector<pii> pos;
        pos.push_back({(269*A+11)%103,(271*A+13)%97});
        for(int i=1;i<B;i++){
            auto [lx,ly] = pos[i-1];
            pos.push_back({(269*lx+11)%103,(271*ly+13)%97});
        }
        vector<int> vis(B);
        vector<int> ans;
        for(int i=0;i<B;i++){
            if(vis[i]) continue;
            queue<pii> q;
            q.push(pos[i]);
            vis[i]=1;
            int cnt=1;
            while(!q.empty()){
                pii a = q.front();
                q.pop();
                for(int i=0;i<B;i++){
                    if(vis[i]) continue;
                    if(chk(a,pos[i],C)){
                        q.push(pos[i]);
                        vis[i]=1;
                        cnt++;
                    }
                }
            }
            ans.push_back(cnt);
        }
        cout << ans.size() << '\n';
        sort(ans.begin(),ans.end());
        for(int i:ans){
            cout << i << ' ';
        }
        cout << '\n';
    }
}