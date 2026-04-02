#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 200005;
const int LOG = 20;
int val[N];
int st[N][LOG];
int n;
void build(){
    for(int i=0;i<n;i++) st[i][0]=val[i];
    for(int j=1;j<LOG;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            st[i][j] = min(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
}
int query(int l,int r){
    if(r==-1) return 0;
    int lg=__lg(r-l+1);
    return min(st[l][lg],st[r-(1<<lg)+1][lg]);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    build();
    int mn = 1e9+9;
    stack<int> s;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        while(!s.empty()&&val[s.top()]<val[i]){
            int t = s.top();
            ans[t]=i;
            s.pop();
        }
        s.push(i);
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+= query(i,ans[i]);
    }
    cout << sum;
}