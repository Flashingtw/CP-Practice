#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct ppp{
    int val,idx;
    bool operator<(ppp ot){
        if(val==ot.val) return idx<ot.idx;
        return val>ot.val;
    }
};
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> v(n+1);
    vector<ppp> a(n);
    vector<int> cnt(m+1);
    for(int i=1;i<=n;i++){
        int val;
        cin>>val;
        a[i-1] = {val,i};
        int c;
        cin>>c;
        for(int s=0;s<c;s++){
            int aaa;
            cin>>aaa;
            v[i].push_back(aaa);
        }
    }
    sort(a.begin(),a.end());
    for(int i=0;i<k;i++){
        for(int aa:v[a[i].idx]){
            cnt[aa]++;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(cnt[i]==k) ans++;
    }
    cout << ans;
}