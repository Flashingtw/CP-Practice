#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<pair<int,int>> pq;
    int n;
    while(cin>>n){
        int a,b,start=0,ans=0;
        for (int i=0;i<n;i++) {
            cin>>a>>b;
            pq.emplace(b,a);
        }
        while (!pq.empty()) {
            start+=pq.top().second;
            ans = max (start + pq.top().first,ans);
            pq.pop();
        }
        cout << ans << "\n";
    }
}