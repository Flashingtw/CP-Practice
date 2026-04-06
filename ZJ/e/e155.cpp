#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        cout << "Discarded cards:";
        while (q.size() > 1) {
            cout << " " << q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            if (q.size() > 1) {
                cout << ",";
            }
        }
        cout << "\nRemaining card: " << q.front() << "\n";
    }
    return 0;
}