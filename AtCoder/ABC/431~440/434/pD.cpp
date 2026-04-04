#include <bits/stdc++.h>
#define D 2005][2005
using namespace std;
int diff[D],prefix[D],one[D];
struct cloud{
    int u,d,l,r;
};
int main(){
    int n;
    cin>>n;
    vector<cloud> v(n);
    for(int i=0;i<n;i++){
        int u,d,l,r;
        cin>>u>>d>>l>>r;
        diff[u][l]++;
        diff[u][r+1]--;
        diff[d+1][l]--;
        diff[d+1][r+1]++;
        v[i] = {u,d,l,r};
    }
    int zero=0;
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=2000;j++){
            prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+diff[i][j];
            one[i][j] = one[i-1][j]+one[i][j-1]-one[i-1][j-1];
            if(prefix[i][j]==1) one[i][j]++;            
            else if (prefix[i][j]==0) zero++;
        }
    }
    for(auto [u,d,l,r]:v){
        int ans = one[d][r]-one[d][l-1]-one[u-1][r]+one[u-1][l-1];
        cout << zero+ans << "\n";
    }
}