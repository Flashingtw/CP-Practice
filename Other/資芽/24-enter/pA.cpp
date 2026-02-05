#include <bits/stdc++.h>
using namespace std;
int grid[1010][1010];
bool vis[1010][1010];
typedef pair<int,int> pii;

int main(){
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    for(int i=0;i<=n+1;i++) grid[i][0]=grid[i][m+1]=-1;
    for(int j=0;j<=m+1;j++) grid[0][j]=grid[n+1][j]=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    int t;
    cin>>t;
    string s;
    cin>>s;
    int ans=grid[r][c];
    int cur_r=r,cur_c=c;
    for(char c:s){
        int next_r=cur_r,next_c=cur_c;
        if(c=='U'&&grid[cur_r-1][cur_c]!=-1) next_r--;
        if(c=='D'&&grid[cur_r+1][cur_c]!=-1) next_r++;
        if(c=='L'&&grid[cur_r][cur_c-1]!=-1) next_c--;
        if(c=='R'&&grid[cur_r][cur_c+1]!=-1) next_c++;
        
        if(!vis[next_r][next_c]){
            vis[next_r][next_c]=1;
            ans+=grid[next_r][next_c];
        }
        cur_r=next_r;
        cur_c=next_c;
    }
    cout << ans;
}