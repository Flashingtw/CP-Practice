#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct ln{
    int l,r;
    bool operator<(ln o){
        return r<o.r;
    }
};
int main(){
    int n;
    cin>>n;
    vector<ln> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].l>>v[i].r;
    }
    sort(v.begin(),v.end());
    int cur=v[0].r,ans=1;
    for(int i=1;i<n;i++){
        if(v[i].l>=cur){
            ans++;
            cur = v[i].r;
        }
    }
    cout << ans;
}