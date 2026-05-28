#include <bits/stdc++.h>
using namespace std;
struct qest{
    double a,b,c;
};
double s(vector<qest> &v,double t){
    double mx=0;
    for(auto &[a,b,c]:v){
        mx = max(mx,a*(t-b)*(t-b)+c);
    }
    return mx;
}
void solve(){
    int n;
    cin>>n;
    vector<qest> v(n);
    for(int i=0;i<n;i++) cin>>v[i].a>>v[i].b>>v[i].c;
    double l=0,r=300;
    for(int cnt=0;cnt<100;cnt++){
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;
        if(s(v,m1)<s(v,m2)){
            r=m2;
        }
        else l = m1;
    }
    cout << fixed << setprecision(10) << s(v,r) << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}