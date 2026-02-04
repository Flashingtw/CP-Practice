#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    priority_queue<long long,vector<long long>,greater<>> pq;
    for (int i=0;i<m;i++) {
        long long num;
        cin>>num;
        pq.push(num);
    }
    long long ans=0;
    for (int i=0;i<n-m;i++) {
        long long num;
        cin>>num;
        long long t = pq.top();
        pq.pop();
        ans = max(ans,t+num);
        pq.push(t+num);
    }
    cout << ans;
}