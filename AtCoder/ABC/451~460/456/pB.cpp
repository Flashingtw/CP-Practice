#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int d[4][7];
int four[4],five[4],six[4];
int main(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=6;j++){
            cin>>d[i][j];
            if(d[i][j]==4) four[i]++;
            if(d[i][j]==5) five[i]++;
            if(d[i][j]==6) six[i]++;
        }
    }
    vector<int> v = {1,2,3};
    ll ans=0;
    do{
        ans+= four[v[0]]*five[v[1]]*six[v[2]];
    }
    while(next_permutation(v.begin(),v.end()));
    cout << fixed << setprecision(15) << 1.0*ans/216 << '\n';
}