#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char grid[105][105];
int main(){
    int h,w,k;
    cin>>h>>w>>k;
    char c1,c2;
    cin>>c1>>c2;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int cnt=1;cnt<=k;cnt++){
            for(int j=1;j<=w;j++){
                for(int cntt=1;cntt<=k;cntt++){
                    cout << (grid[i][j]=='#'?c1:c2);
                }
            }
            cout << "\n";
        }
    }
}