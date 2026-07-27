#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int INF = 1e9+9;
const int N = 1.2e6+5;

ll cnt[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<pii> v(n+1);
    for(int i=1;i<=n;i++) {
        cnt[i] = 999*i;
        v[i] = {cnt[i],i};
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq(v.begin()+1,v.begin()+1+n);
    
    string ans;
    ans.reserve(q);
    while(q--){
        int p;
        cin>>p;
        while(pq.top().first!=cnt[pq.top().second]) pq.pop();
        ll a = pq.top().first;
        int idx = pq.top().second;
        if(p==idx) {
            ans.push_back('0');
            continue;
        }
        ll diff = cnt[p]-a;
        ll cur = diff/2;
        bool chk = diff&1;
        cnt[p] -= cur+chk;
        cnt[idx] += cur;

        pq.push({cnt[p],p});
        pq.push({cnt[idx],idx});

        ans.push_back(chk?'1':'0');
    }
    cout << ans << '\n';
}