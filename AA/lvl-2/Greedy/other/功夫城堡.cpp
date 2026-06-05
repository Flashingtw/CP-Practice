#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;

int n;
bool chk(vector<pll> &v){
    sort(v.begin(),v.end());
    priority_queue<ll,vector<ll>,greater<>> pq;
    int j=0;
    for(int i=1;i<=n;i++){
        while(j<n&&v[j].first<=i){
            pq.push(v[j].second);
            j++;
        }
        if(!pq.empty()&&pq.top()>=i){
            pq.pop();
        }
        else return 0;
    }
    return 1;
}

void slv(){
    vector<pll> w(n),h(n);
    for(int i=0;i<n;i++){
        cin>>w[i].first>>w[i].second>>h[i].first>>h[i].second;
    }
    if(chk(w)&&chk(h)){
        cout << "YES" << '\n';
    }
    else cout << "NO" << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n){
        slv();
    }
}