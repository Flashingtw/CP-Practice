#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // 這個宣告一次就好
    int n = 20;
    long long x = rng() % n;
    cout << x+1 << '\n';
}