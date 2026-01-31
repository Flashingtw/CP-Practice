#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N,K;
    cin >> N >> K;
    vector<int> v[1000005];
    for (int i = 0; i < K; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < N; i++) sort(v[i].begin(), v[i].end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v[i+1].size(); j++) {
            if (j!=0) cout << " ";
            cout << v[i+1][j];
        }
        cout << "\n";
    }
}