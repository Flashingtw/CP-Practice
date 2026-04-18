#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct point{ll x,y;};

bool solve(){
    int n;
    ll rx,ry;
    cin>>n>>rx>>ry;

    vector<int> x(n),y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];

    vector<int> sx=x,sy=y;
    sort(sx.begin(),sx.end());
    sort(sy.begin(),sy.end());
    for(int i=1;i<n;i++){
        if(sx[i]==sx[i-1]) return 0;
        if(sy[i]==sy[i-1]) return 0;
    }

    vector<point> q[4];
    for(int i=0;i<n;i++){
        ll dx=x[i]-rx,dy=y[i]-ry;
        if(dx>0&&dy>0) q[0].push_back({dx,dy});
        else if(dx<0&&dy>0) q[1].push_back({-dx,dy});
        else if(dx<0&&dy<0) q[2].push_back({-dx,-dy});
        else if(dx>0&&dy<0) q[3].push_back({dx,-dy});
    }

    for(int i=0;i<4;i++){
        sort(q[i].begin(),q[i].end(),[](point a,point b){return a.x<b.x;});
        for(int j=1;j<q[i].size();j++){
            if(q[i][j].y<q[i][j-1].y) return 0;
        }
    }

    int p[4]={0};
    while(1){
        if(p[0]==q[0].size()||p[1]==q[1].size()||p[2]==q[2].size()||p[3]==q[3].size()) return 1;

        bool m=0;
        if(q[0][p[0]].x<q[3][p[3]].x&&q[0][p[0]].y<q[1][p[1]].y) p[0]++,m=1;
        else if(q[1][p[1]].x<q[2][p[2]].x&&q[1][p[1]].y<q[0][p[0]].y) p[1]++,m=1;
        else if(q[2][p[2]].x<q[1][p[1]].x&&q[2][p[2]].y<q[3][p[3]].y) p[2]++,m=1;
        else if(q[3][p[3]].x<q[0][p[0]].x&&q[3][p[3]].y<q[2][p[2]].y) p[3]++,m=1;

        if(!m) return 0;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) cout << (solve()?"Yes":"No") << '\n';
}