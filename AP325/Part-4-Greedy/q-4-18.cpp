#include <bits/stdc++.h>
using namespace std;
long long n,D;
vector<long long> v;
bool check(int k) {
    priority_queue<long long, vector<long long>,greater<>> pq;
    for (int i=0;i<k;i++) {
        pq.push(0);
    }
    long long ear=0,finished=0;
    for (int i : v) {
        ear = pq.top();
        pq.pop();
        finished = ear + i;
        if (finished>D) return false;
        pq.push(finished);
    }
    return true;
}
int main() {
    cin>>n>>D;
    v.resize(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    long long l=0,r=n-1,ans=INT_MAX;
    while (l<=r) {
        long long mid = (l+r)/2;
        if (check(mid)) {
            ans = min(ans,mid);
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans;
}