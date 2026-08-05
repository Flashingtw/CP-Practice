#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e7+5;
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    k--;
    int x,A,b,c;
    cin>>x>>A>>b>>c;
    a[0]=x;
    for(int i=1;i<n;i++) a[i] = (1LL*A*a[i-1]+b)%c;
    deque<int> dq;
    ll ans=0;
    for(int i=0;i<n;i++){
        while(!dq.empty()&&i-dq.front()>k) dq.pop_front();
        while(!dq.empty()&&a[i]<=a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if(i>=k) ans^=a[dq.front()];
    }
    cout << ans << '\n';
}