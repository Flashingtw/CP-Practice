#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    priority_queue<int,vector<int>,greater<int>> pq;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pq.push(a);
    }
    while(m--){
        int t;
        cin>>t;
        if(!t){
            cout << pq.top() << '\n';
        }
        else if(t==1){
            int a = pq.top();
            pq.pop();
            cout << pq.top() << '\n';
            pq.push(a);
        }
        else if(t==2){
            pq.pop();
        }
        else if(t==3){
            int a;
            cin>>a;
            pq.push(a);
        }
    }
}