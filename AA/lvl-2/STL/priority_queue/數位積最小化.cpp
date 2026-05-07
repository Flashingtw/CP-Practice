#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll cnt(ll a){
    ll sum=1;
    while(a>1){
        sum*=a%10;
        a/=10;
    }
    return sum;
}
int main(){
    ll n,k;
    cin>>n>>k;
    priority_queue<ll> pq;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        pq.push(a);
    }
    for(int i=0;i<k;i++){
        if(pq.top()<10){
            break;
        }
        ll a = pq.top();
        pq.pop();
        pq.push(cnt(a));
    }
    cout << pq.top() << '\n';
}