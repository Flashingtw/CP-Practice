#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[2*N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        adj[a].push_back(b);
    }
    vector<int> st;
    bool chk=0;
    for(int i=1;i<=2*n;i++){
        if(chk) break;
        sort(adj[i].begin(),adj[i].end(),greater());
        while(!st.empty()&&i>=st.back()) st.pop_back();
        for(int u:adj[i]){
            if(!st.empty()&&u>st.back()){
                chk=1;
                break;
            }
            st.push_back(u);
        }
    }
    cout << (chk?"Yes":"No") << '\n';
}