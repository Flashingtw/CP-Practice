#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n;
bool chk(double tar,vector<int> &pos,vector<int> &t){
    double mxl=0,mnr=1e9+1;
    for(int i=0;i<n;i++){
        double diff = max(0.0,tar-t[i]);
        mxl = max(mxl,pos[i]-diff);
        mnr = min(mnr,pos[i]+diff);
    }
    return mnr>=mxl;
}
void solve(){
    cin>>n;
    vector<int> pos(n),t(n);
    for(int i=0;i<n;i++) cin>>pos[i];
    for(int i=0;i<n;i++) cin>>t[i];
    double l = 0,r = 1e9,ans=0;
    for(int cnt=0;cnt<200;cnt++){
        double mid = (l+r)/2;
        if(chk(mid,pos,t)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    double mxl=0,mnr=1e9+1;
    for(int i=0;i<n;i++){
        double diff = max(0.0,ans-t[i]);
        mxl = max(mxl,pos[i]-diff);
        mnr = min(mnr,pos[i]+diff);
    }
    cout << fixed << setprecision(15) << mnr << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}