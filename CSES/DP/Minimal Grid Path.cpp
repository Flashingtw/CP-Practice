#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<string> grid(n);
    for (int i=0;i<n;i++) cin>>grid[i];
    string ans="";
    ans+=grid[0][0];
    vector<pair<int,int>> cur;
    cur.push_back({0,0});
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i=0;i<2*n-2;i++) {
        //find min_char
        char min_char = '{';
        for (auto r : cur) {
            int x = r.first;
            int y = r.second;
            if (x+1<n) min_char = min(min_char, grid[x+1][y]);
            if (y+1<n) min_char = min(min_char,grid[x][y+1]);
        }
        ans+=min_char;
        vector<pair<int,int>> next;
        for (auto r :cur) {
            int x = r.first;
            int y = r.second;
            if (x+1<n&&grid[x+1][y]==min_char&&!vis[x+1][y]) {
                vis[x+1][y] = true;
                next.push_back({x+1,y});
            }
            if (y+1<n&&grid[x][y+1]==min_char&&!vis[x][y+1]) {
                vis[x][y+1] = true;
                next.push_back({x,y+1});
            }
        }
        swap(cur,next);
    }
    cout << ans;
}