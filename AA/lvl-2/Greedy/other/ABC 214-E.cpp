#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool solve(){
    int n;
    cin>>n;
    vector<pii> v(n);
    for(auto &[r,l]:v) cin>>l>>r;
    sort(v.begin(),v.end());
    int cur=0;//next can use
    for(auto [r,l]:v){
        if(cur<l) cur=l;
        if(cur>r){
            return 0;
        }
        cur++;
    }
    return 1;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        if(solve()){
            cout << "Yes" << '\n';
        }
        else cout << "No" << '\n';
    }
}