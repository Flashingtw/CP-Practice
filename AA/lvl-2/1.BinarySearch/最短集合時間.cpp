#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double,double> pdd;

bool chk(double tar,vector<pdd> a){
    double mx_l=-1e9-1,mn_r=1e9+1;
    for(auto [x,v]:a){
        mx_l = max(mx_l,x-(v*tar));
        mn_r = min(mn_r,x+(v*tar));
    }
    return mx_l<=mn_r;
}

int main(){
    int n;
    cin>>n;
    vector<pdd> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    double l = 0,r=1e10;
    for(int i=0;i<100;i++){
        double mid = (l+r)/2;
        if (chk(mid,a)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << fixed << setprecision(15) << (l+r)/2;
}