#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct ev{
    ll a,b,c,p;
};
bool solve(){
    ll n;
    cin>>n;
    vector<ev> v(n);
    for(auto &[a,b,c,p]:v){
        cin>>a>>b>>c>>p;
    }
    ll has=0,ra=0,rb=0,rc=0,rd=0;
    for(auto [a,b,c,p]:v){
        ll da = max(0LL,a-ra);
        ll db = max(0LL,b-rb);
        ll dc = max(0LL,c-rc);
        ll dd = p-rd;
        if(da+db+dc<dd){
            ra = max(a,ra);
            rb = max(b,rb);
            rc = max(c,rc);
            rd += da+db+dc+1;
        }
        else return 0;
    }
    return 1;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        if(solve()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}