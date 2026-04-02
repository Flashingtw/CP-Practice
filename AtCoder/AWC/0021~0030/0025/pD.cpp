#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct nx{
    int num,idx;
    bool operator<(nx ot){
        return num<ot.num;
    }
};
int vis[200005];
int main(){
    ll n,s,q;
    cin>>n>>s>>q;
    vector<nx> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].num;
        v[i].idx = i+1;
    }
    sort(v.begin(),v.end());
    int i=s;
    for(int idx=0;idx<n;idx++){
        if(v[idx].idx==s) {
            i=idx;
            break;
        }
    }
    
    vector<int> step;
    int cnt=1;
    int sti,cy_sz;
    while(1){
        if(vis[i]!=0){
            sti=vis[i]-1;
            cy_sz=cnt-vis[i];
            break;
        }
        step.push_back(v[i].idx);
        vis[i] = cnt++;
        if(i==0){
            i++;
            continue;
        }
        if(i==n-1){
            i--;
            continue;
        }
        int dl = v[i].num - v[i-1].num;
        int rl = v[i+1].num - v[i].num;
        if (dl<rl) i--;
        else if (rl<dl) i++;
        else{
            if(v[i-1].idx<v[i+1].idx) i--;
            else i++;
        }
    }
    if(q<step.size()) cout << step[q];
    else cout << step[sti + (q-sti)%cy_sz];
}