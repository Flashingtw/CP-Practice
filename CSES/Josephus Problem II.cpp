#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    queue<int> q;
    for (int i=1;i<=n;i++) {
        q.push(i);
    }
    while (!q.empty()) {
        int step = k%q.size();
        for (int i=0;i<step;i++) {
            int first = q.front();
            q.pop();
            q.push(first);
        }
        cout << q.front() << " ";
        q.pop();
    }
}