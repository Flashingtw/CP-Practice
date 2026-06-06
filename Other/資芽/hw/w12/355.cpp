#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;

    vector<pair<long long, long long>> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].first >> pts[i].second;
    }

    long long left = 0, right = 0, back = 0;

    for (int i = 1; i < n - 1; ++i) {
        long long ux = pts[i].first - pts[i-1].first;
        long long uy = pts[i].second - pts[i-1].second;
        long long vx = pts[i+1].first - pts[i].first;
        long long vy = pts[i+1].second - pts[i].second;

        __int128 cross = (__int128)ux * vy - (__int128)uy * vx;
        __int128 dot = (__int128)ux * vx + (__int128)uy * vy;

        if (cross > 0) {
            left++;
        } else if (cross < 0) {
            right++;
        } else if (dot < 0) {
            back++;
        }
    }

    cout << left << " " << right << " " << back << "\n";
}