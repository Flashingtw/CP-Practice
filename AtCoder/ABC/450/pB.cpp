#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int d[105][105];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>d[i][j];
        }
    }
    bool chk=0;
    for(int i=1;i<=n;i++){
        if(chk) break;
        for(int j=i+1;j<=n;j++){
        if(chk) break;
            for(int k=i+1;k<j;k++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    chk=1;
                    break;
                }
            }
        }
    }
    if(chk) cout << "Yes";
    else cout << "No";
}