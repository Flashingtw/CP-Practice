#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    cin>>n;
    priority_queue<long long,vector<long long>,greater<>> pq;
    for (int i=0;i<n;i++) {
        long long num;
        cin>>num;
        pq.push(num);
    }
    long long ans=0;
    while (pq.size()>1) {
        long long n1 = pq.top();
        pq.pop();
        long long n2 = pq.top();
        pq.pop();
        ans+=n1+n2;
        pq.push(n1+n2);
    }
    cout << pq.top() << "\n" << ans;
}