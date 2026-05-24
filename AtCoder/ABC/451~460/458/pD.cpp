#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int x;
    cin>>x;
    int q;
    cin>>q;
    priority_queue<int> low;
    priority_queue<int,vector<int>,greater<int>> high;
    low.push(x);
    while(q--){
        ll a,b;
        cin>>a>>b;
        if(a>low.top()){
            high.push(a);
        }
        else low.push(a);
        if(b>low.top()){
            high.push(b);
        }
        else low.push(b);
        while(low.size()-1>high.size()){
            high.push(low.top());
            low.pop();
        }
        while(high.size()+1>low.size()){
            low.push(high.top());
            high.pop();
        }
        cout << low.top() << '\n';
    }
}