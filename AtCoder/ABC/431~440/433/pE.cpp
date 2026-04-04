#include <bits/stdc++.h>
using namespace std;
bool solve(){
    int n,m;
    cin>>n>>m;
    int v = n*m;
    vector<int> pos_x(v+1,-1),pos_y(v+1,-1);
    vector<int> x(n),y(m);
    bool ok = true;
    for(int i=0;i<n;i++){
        cin>>x[i];
        if(pos_x[x[i]]!=-1) ok=false;
        pos_x[x[i]]=i;
    }
    for(int i=0;i<m;i++){
        cin>>y[i];
        if(pos_y[y[i]]!=-1) ok=false;
        pos_y[y[i]]=i;
    }
    if(!ok) return false;
    vector<int> row,col;
    vector<pair<int,int>> pool;
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i=v;i>=1;i--){
        if(pos_x[i]!=-1&&pos_y[i]!=-1){
            int r=pos_x[i];
            int c=pos_y[i];
            ans[r][c]=i;
            for(int old_c:col){
                pool.push_back({r,old_c});
            }
            for(int old_r:row){
                pool.push_back({old_r,c});
            }
            row.push_back(r);
            col.push_back(c);
        }
        else if (pos_x[i]!=-1) {
            if(col.empty()) return false;
            int r = pos_x[i];
            int ch = col[0];
            ans[r][ch]=i;
            for(int j=1;j<col.size();j++){
                pool.push_back({r,col[j]});
            }
            row.push_back(r);
        }
        else if (pos_y[i]!=-1) {
            if(row.empty()) return false;
            int chr = row[0];
            int c = pos_y[i];
            ans[chr][c]=i;
            for(int j=1;j<row.size();j++){
                pool.push_back({row[j],c});
            }
            col.push_back(c);
        }
        else {
            if(pool.empty()) return false;
            auto [x,y] = pool.back();
            pool.pop_back();
            ans[x][y] = i;
        }
    }
    cout << "Yes\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(!solve()){
            cout << "No\n";
        }
    }
}