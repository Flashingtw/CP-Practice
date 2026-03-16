#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

void solve(){
    int n,k,p,m;
    cin>>n>>k>>p>>m;
    queue<pii> q;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int pn;
    for(int i=1;i<=n;i++) {
        int num;
        cin>>num;
        if(i==p) pn=num;
        q.push({num,i});
    }
    bool chk=0;
    for(int i=0;i<k;i++){
        if(q.front().second==p){
            chk=1;
        }
        else pq.push(q.front());
        q.pop();
    }
    if(k==n){
        cout << m/pn << '\n';
        return;
    }
    int cnt=0;
    while(m>0){
        if(m<pn) break;
        if(chk){
            m-=pn; chk=0;
            q.push({pn,p});
            pq.push(q.front());
            q.pop();
            cnt++;
        }
        else{
            auto [cost,idx] = pq.top();
            pq.pop();
            if(m<cost) break;
            m-=cost;
            q.push({cost,idx});
            if(q.front().second!=p){
                pq.push(q.front());
                q.pop();
            }
            else{
                chk=1;
                q.pop();
            }
        }
    }
    cout << cnt << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}