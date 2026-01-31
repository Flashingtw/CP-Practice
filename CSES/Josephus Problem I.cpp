#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    queue<int> q;
    for (int i=1;i<=n;i++) {
        q.push(i);
    }
    while (!q.empty()) {
        int first = q.front();
        q.pop();
        q.push(first);
        cout << q.front() << " ";
        q.pop();
    }
}