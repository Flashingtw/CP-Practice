#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
struct point{
    int pos,idx;
    bool operator<(point ot){
        return pos<ot.pos;
    }
};
int cnt[N];
int main(){
    vector<int> a(7);
    for(int i=1;i<=6;i++) cin>>a[i];
    int n;
    cin>>n;
    vector<point> v;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        for(int j=1;j<=6;j++){
            v.push_back({p-a[j],i+1});
        }
    }
    sort(v.begin(),v.end());
    int cur=0;
    int m = v.size();
    int l=0,ans = 2e9;
    for(int r=0;r<m;r++){
        if(cnt[v[r].idx]++==0) cur++;
        while(cur==n&&cnt[v[l].idx]>1){
            cnt[v[l++].idx]--;
        }
        if(cur==n) ans = min(ans,v[r].pos-v[l].pos);
    }
    cout << ans << '\n';
}