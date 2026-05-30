#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n;
vector<int> a,p;
bool chk(int t){
    int sz = a.size();
    int idx = 0;
    for(int i=0;i<p.size();i++){
        if(idx==sz) break;
        int pi = p[i];
        if(a[idx]<pi){
            //往左的距離d1
            int d1 = pi-a[idx];
            if(d1>t) return 0;
            //先往右再往左 往右走到R再走回來 2*(R-pi) + d1 <=t -> R<=pi+(t-d1)/2 
            //先往左再往右 -> R<=t-d1*2+pi
            int r1 = pi+(t-d1)/2,r2 = t-d1*2+pi;
            int r = max({r1,r2,pi});
            while(idx<sz&&a[idx]<=r) idx++;
        }
        else{
            int r = pi+t;
            while(idx<sz&&a[idx]<=r) idx++;
        }
    }
    return idx==sz;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='*') a.push_back(i);
        if(s[i]=='P') p.push_back(i);
    }
    int l = 0,r=2*n,ans=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << '\n';
}