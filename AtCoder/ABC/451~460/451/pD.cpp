#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
vector<string> a(30);
set<ll> st;
unordered_set<ll> vis;
int main(){
    int n;
    cin>>n;
    a[0]="1";
    queue<string> q;
    q.push("1");
    vis.insert(1);
    for(int i=1;i<=29;i++){
        int s=1;
        for(int d=1;d<=i;d++){
            s*=2;
        }
        a[i] = to_string(s);
        q.push(a[i]);
        vis.insert(s);
    }
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        st.insert(stoll(cur));
        for(string &w:a){
            string nxt = cur+w;
            if(nxt.length()>10) continue;
            ll num = stoll(nxt);
            if(num>INF) continue;
            if(!vis.count(num)){
                q.push(nxt);
                vis.insert(num);
            }
        }
    }
    vector<ll> ans(st.begin(),st.end());
    cout << ans[n-1];
}