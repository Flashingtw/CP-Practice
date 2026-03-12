#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
char grid[2005][2005];
int row[2005][26],col[2005][26];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            row[j][grid[i][j]-'a']++;
            col[i][grid[i][j]-'a']++;
        }
    }
    bool chk=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[j][grid[i][j]-'a']==1&&col[i][grid[i][j]-'a']==1){
                cout << grid[i][j];
                chk=1;
            }
        }
    }
    if(!chk) cout << '\n';
}