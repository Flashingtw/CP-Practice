#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,d;
pii chk(double mid,vector<int> &v){
    vector<double> p(n+1);
    for(int i=1;i<=n;i++) p[i] = p[i-1] + (1.0*v[i]-mid);
    double mi = 1e18;
    int fi=-1,fj=-1,mij=-1;
    for(int i=d;i<=n;i++){
        int j = i-d;
        if(p[j]<mi) {
            mij = j;
            mi = p[j];
        }
        if(p[i]-mi>=0) {
            fi = i;
            fj = mij+1;
            break;
        }
    }
    return (make_pair(fi==-1?-1:fj,fi));
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>d;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    double l=-1,r=101;
    pii ans;
    for(int i=0;i<100;i++){
        double mid = l+(r-l)/2;
        pii a = chk(mid,v); 
        if(a!=make_pair(-1,-1)){
            ans = a;
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << ans.first << " " << ans.second << '\n';
}