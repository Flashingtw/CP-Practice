#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>k>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pq.push(a);
    }
    ll ans=0;
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        ans+=a+b;
        pq.push(a+b);
    }
    cout << ans << '\n';
}
// a,b,c;
// a+b , c; (a+b)
// a+b+c; (2a+2b+c) <- 先合小的