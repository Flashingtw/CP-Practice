#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n+2);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int i=0,j=n-1;
    int cnt=0,ans=0;
    
    int l=0,r=0;
    //i,j為下一顆吃的糖
    while(i<=j){
        if(l<r){
            l+=v[i++];
        }
        else{
            r+=v[j--];
        }
        cnt++;
        if(l==r) ans=max(ans,cnt);
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}