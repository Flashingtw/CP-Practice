#include <algorithm>
#include <iostream>
#include <vector>
#define N 100010
using namespace std;
int dis(int from[],int to[],int n) {
    if (n<1) return 0;
    int num=1;
    vector v(from,from+n);
    sort(v.begin(),v.end());
    to[0]=v[0];
    for (int i=1;i<n;i++) {
        if (v[i]!=v[i-1]) to[num++] = v[i];
    }
    return num;
}

int main() {
    int a[N],b[N],n,k;
    cin>>n;
    for (int i=0;i<n;i++) cin>> a[i];
    k = dis(a,b,n);
    cout << k << "\n";
    for (int i=0;i<k;i++) {
        cout << b[i] << " ";
    }
}