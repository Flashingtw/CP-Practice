#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs_step(queue<int>& q, vector<vector<int>>& v, vector<bool>& check) {
    if (q.empty()) return;
    const int n = q.front();
    q.pop();
    for (int neighbor : v[n]) {
        if (!check[neighbor]) {
            check[neighbor] = true;
            q.push(neighbor);
        }
    }
}

int main() {
    int N, M, L, Q;
    cin >> N >> M >> L >> Q;
    vector<vector<int>> v(N + 1);
    vector<bool> check(N + 1, false);
    queue<int> q;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 0; i < L; ++i) {
        int a;
        cin >> a;
        if (!check[a]) {
            check[a] = true;
            q.push(a);
        }
    }
    while (!q.empty()) {
        bfs_step(q, v, check);
    }
    for (int i = 0; i < Q; ++i) {
        int a;
        cin >> a;
        cout << (check[a] != true ? "YA~~" : "TUIHUOOOOOO") << "\n";
    }
    return 0;
}