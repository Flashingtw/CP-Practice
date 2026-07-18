#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
char grid[15][15];
int dd[] = {1,0,-1,0,1};
struct state{
    vector<pii> has;
    int d;
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int h,w;
    cin>>h>>w;
    for(int i=0;i<=h;i++){
        grid[i][0] = grid[i][w+1] = '-';
    }
    for(int i=0;i<=w;i++){
        grid[0][i] = grid[h+1][i] = '-';
    }
    vector<pii> has;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='#') has.push_back({i,j});
        }
    }
    queue<state> q;
    sort(has.begin(),has.end());
    q.push({has,0});
    set<vector<pii>> s;
    s.insert(has);
    while(!q.empty()){
        auto [a,dis] = q.front();
        q.pop();
        if(a.empty()){
            cout << dis << '\n';
            return 0;
        }
        for(int d=0;d<4;d++){
            vector<pii> b;
            bool p=1;
            for(auto [x,y]:a){
                int nx = x+dd[d];
                int ny = y+dd[d+1];
                if(grid[nx][ny]=='-'){
                    continue;
                }
                else if(grid[nx][ny]=='T'){
                    p=0;
                    break;
                }
                else b.push_back({nx,ny});
            }
            sort(b.begin(),b.end());
            if(s.find(b)==s.end()&&p){
                q.push({b,dis+1});
                s.insert(b);
            }
        }
    }
    cout << -1 << '\n';
}