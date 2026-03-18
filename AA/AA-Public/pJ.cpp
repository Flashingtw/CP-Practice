#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dist(int v){
    return v*v;
}
int cnt[2000005];
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        for(int j=0;j<i;j++){
            cnt[dist(x[i]-x[j])+dist(y[i]-y[j])]++;
        }
    }
    int ct=0;
    double ans=0;
    for(int i=0;i<2000001;i++){
        if(cnt[i]){
            ans+=sqrt(i);
            ct++;
        }
    }
    cout << fixed << setprecision(4) << ans/ct ;
}