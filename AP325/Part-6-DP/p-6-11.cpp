#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define P LL(1e9+9)

vector<LL> memo;

LL cat(LL n) {
    if (memo[n]>=0) return memo[n];
    LL sum=0;
    for (int i=0;i<n;i++) {
        LL t = cat(i)*cat(n-1-i)%P;
        sum = (sum+t)%P;
    }
    memo[n] = sum;
    return memo[n];
}

int main() {
    int n;
    cin>>n;
    memo.resize(n+1,-1);
    memo[0]=1;
    cout << cat(n);
}