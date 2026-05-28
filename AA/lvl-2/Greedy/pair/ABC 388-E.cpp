#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v) cin>>i;
    priority_queue<int,vector<int>,greater<int>> l,r;
    for(int i=0;i<n/2;i++) l.push(v[i]);
    for(int i=n/2;i<n;i++) r.push(v[i]);
    int cnt=0;
    while(!l.empty()&&!r.empty()){
        int a = l.top();
        int b = r.top();
        if(a*2<=b){
            l.pop();
            r.pop();
            cnt++;
        }
        else{
            r.pop();
        }
    }
    cout << cnt << '\n';
}