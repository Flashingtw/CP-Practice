#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<char> s(n+1);
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) {
        ll x;
        cin>>x;
        a[i] = a[i-1]+x;
    }
    int l=0;
    int cnt=0;
    deque<int> dq={0};
    ll ans=0;
    for(int r=1;r<=n;r++){
        if(s[r]=='1') cnt++;
        while(cnt>k){
            if(s[++l]=='1') cnt--;
        }
        while(!dq.empty()&&dq.front()<l) dq.pop_front();
        if(!dq.empty()) ans = max(ans,a[r]-a[dq.front()]);
        while(!dq.empty()&&a[dq.back()]>a[r]) dq.pop_back();
        dq.push_back(r);
    }
    cout << ans << '\n';
}
//算答案算太慢,初始值,條件判斷