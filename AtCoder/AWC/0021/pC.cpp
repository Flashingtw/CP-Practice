#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct shop{
    vector<int> v;
    int sz,cost;
    ll total=0;
    void init(int _sz,int cos){
        sz=_sz;
        cost = cos;
        v.resize(_sz,0);
    }
    void add(){
        for(int i=0;i<sz;i++) {
            cin>>v[i];
            total+=v[i];
        }
        sort(v.begin(),v.end(),greater());
    }
    bool operator<(shop other){
        return total-cost>other.total-other.cost;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    vector<shop> v(n);
    for(int i=0;i<n;i++){
        int c,m;
        cin>>c>>m;
        v[i].init(m,c);
        v[i].add();
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=0;i<k;i++){
        ll diff = v[i].total-v[i].cost;
        if(diff<0) break;
        ans+=diff;
    }
    cout << ans;
}