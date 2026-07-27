#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,d;
bool chk(double mid,vector<int> &v){
    vector<double> p(n+1);
    for(int i=1;i<=n;i++) p[i] = p[i-1] + (1.0*v[i]-mid);
    double mi = 1e18;
    for(int i=d;i<=n;i++){
        int j = i-d;
        mi = min(mi,p[j]);
        if(p[i]-mi>=0) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>d;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    double l=0,r=101,ans;
    for(int i=0;i<100;i++){
        double mid = l+(r-l)/2;
        if(chk(mid,v)){
            ans = mid;
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
}