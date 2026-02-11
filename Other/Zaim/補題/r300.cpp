#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long ll;
int n,m,k;
int lig[N];
int isl[N];
bool chk(int r){
    int cnt=0,cur=0;
    while(cur<m){
        int pos = isl[cur];
        auto it = upper_bound(lig,lig+n,pos+r);
        if (it == lig) return false;
        it--;
        if(*it<pos-r) return false;
        cnt++;
        cur = upper_bound(isl,isl+m,*it+r)-isl;
    }
    return cnt<=k;
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>lig[i];
    for(int i=0;i<m;i++) cin>>isl[i];
    if(n==0){
        cout << -1;
        return 0;
    }
    int l=0,r=1e9+9;
    int ans=-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(chk(mid)) {
            r=mid-1;
            ans = mid;
        }
        else l=mid+1;
    }
    cout << ans;
}