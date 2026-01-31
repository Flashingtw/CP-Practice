#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int,pair<int,int>> mp = {
    {90,{0,1}},
    {180,{1,0}},
    {270,{0,-1}},
    {0,{-1,0}}};
int main() {
    int M,N,k,r,c;
    cin>>M>>N>>k>>r>>c;
    vector<vector<int>> v(M,vector<int>(N,0));
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            cin>>v[i][j];
        }
    }
    LL score=0,count=0,angle=90;
    while (1) {
        if (v[r][c]==0) {
            break;
        }//如果所在位置為0 break
        score+=v[r][c];
        v[r][c]--;
        count++;
        if (score%k==0) angle = (angle+90)%360;
        int dx=r+mp[angle].first,dy=c+mp[angle].second;
        while (dx<0||dy<0||dx>=M||dy>=N||v[dx][dy]==-1) {
            angle= (angle+90)%360;
            dx=r+mp[angle].first;
            dy=c+mp[angle].second;
        }
        r = dx;
        c = dy;
    }
    cout << count;
}