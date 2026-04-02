#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
char grid[505][505];

int main(){
    int h,w,n;
    cin>>h>>w>>n;
    int cnt=0;
    for(int i=0;i<=h+1;i++) grid[i][0] = grid[i][w+1] = '-';
    for(int i=0;i<=w+1;i++) grid[0][i] = grid[h+1][i] = '-';
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='#') cnt++;
        }
    }
    if(grid[1][1]=='#'){
        cnt--;
        grid[1][1]='.';
    } 
    string t;
    cin>>t;
    int x=1,y=1;
    for(char c:t){
        int nx=x,ny=y;
        if(c=='U') nx--;
        if(c=='D') nx++;
        if(c=='L') ny--;
        if(c=='R') ny++;

        if(grid[nx][ny]=='-') continue;
        x = nx,y = ny;
        if(grid[x][y]=='#') {
            cnt--;
            grid[x][y]='.';
        }
    }
    cout << cnt;
}