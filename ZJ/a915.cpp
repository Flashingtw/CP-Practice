#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >>y;
        v.emplace_back(x,y);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
}
