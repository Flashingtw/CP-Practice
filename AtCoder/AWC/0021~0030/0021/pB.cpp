#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int v[N];
void solve(){
    int k;
    cin>>k;
    int mx=0,idx=0;
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        if(v[num]>mx){
            idx=num;
            mx = v[num];
        }
        else if (v[num]==mx){
            if(num<idx) idx=num;
        }
    }
    cout << idx << '\n';
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        solve();
    }
}