#include <bits/stdc++.h>
using namespace std;
vector<int> v;
typedef long long LL;
LL rect(int le,int ri) {
    if (le>=ri) return 0;
    if (le+1>=ri) return v[le];
    int m = (le+ri)/2;
    LL max_rect = max(rect(m+1,ri),rect(le,m));

    LL i=m,j=m,height = v[m],largest=0;
    while (le<=i||j<=ri) {
        if (i<le) height = v[j];
        else if (j>=ri) height = v[i];
        else height = max(v[i],v[j]);
        while (i>=le&&v[i]>=height) i--;
        while (j<=ri&&v[j]>=height) j++;
        largest = max(largest,(j-i-1)*height);
    }
    return max(largest,max_rect);
}

int main() {
    int n;
    cin>>n;
    v.resize(n);
    for (int i=0;i<n;i++) cin>>v[i];
    cout << rect(0,n);
}