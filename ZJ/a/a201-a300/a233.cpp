#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++) cout << v[i] << " ";
}