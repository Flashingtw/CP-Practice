#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
map<int,set<int>> row,col;

set<pii> vis;
struct state{
    int x,y;
    int d;
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    int sx,sy,gx,gy;
    cin>>sx>>sy>>gx>>gy;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        col[y].insert(x);
        row[x].insert(y);
    }
    queue<state> q;
    q.push({sx,sy,0});
    vis.insert({sx,sy});
    while(!q.empty()){
        auto [x,y,d] = q.front();
        q.pop();
        if(x==gx&&y==gy){
            cout << d << '\n';
            return 0;
        }
        // +y -y
        {
            auto it = row[x].lower_bound(y);
            if(it!=row[x].end()){
                int ny = *it-1;
                if(vis.find({x,ny})==vis.end()){
                    q.push({x,ny,d+1});
                    vis.insert({x,ny});
                }
            }
            if(it!=row[x].begin()){
                int ny = *prev(it)+1;
                if(vis.find({x,ny})==vis.end()){
                    q.push({x,ny,d+1});
                    vis.insert({x,ny});
                }
            }
        }
        // +x -x
        {
            auto it = col[y].lower_bound(x);
            if(it!=col[y].end()){
                int nx = *it-1;
                if(vis.find({nx,y})==vis.end()){
                    q.push({nx,y,d+1});
                    vis.insert({nx,y});
                }
            }
            if(it!=col[y].begin()){
                int nx = *prev(it)+1;
                if(vis.find({nx,y})==vis.end()){
                    q.push({nx,y,d+1});
                    vis.insert({nx,y});
                }
            }
        }
    }
    cout << -1 << '\n';
}