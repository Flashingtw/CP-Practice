#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++) pq.push(v[i]);
    for(int i=k;i<n;i++){
        cout << pq.top() << '\n';
        if(v[i]>pq.top()){
            pq.push(v[i]);
            pq.pop();
        }
    }
    cout << pq.top() << '\n';
}