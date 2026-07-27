#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n,k;
int s[N],siz[N],p[N];
int max_size=0;
multiset<int> all_size;

int find(int x) {
    // just find
    if (p[x]==x) return x;
    return p[x] = find(p[x]);
}

void merge(int x,int y) {
    //find parents
    x = find(x);
    y = find(y);
    if (x==y) return;
    //erase the size
    all_size.erase(all_size.find(siz[x]));
    all_size.erase(all_size.find(siz[y]));
    //change x parent to y
    p[x] = y;
    //add x size to y size
    siz[y] += siz[x];
    //insert new size,renew maxsize
    all_size.insert(siz[y]);
    max_size = max(max_size,siz[y]);
}

int main() {
    cin>>n>>k;
    n++;
    fill(s,s+n,0);
    //initialize array
    for (int i = 0; i <= n; i++) {
        p[i] = i;
        siz[i] = 1;
        s[i] = 0;
    }
    //input array
    for (int i=1;i<n;i++) {
        cin>>s[i];
        if (s[i]==1) {
            all_size.insert(1);
            max_size = max(max_size,1);
            if (s[i-1]==1) merge(i,i-1);
        }
    }
    long long tmax =0;
    long long tmin =0;
    if (!all_size.empty()) {
        tmax = max_size;
        tmin = *all_size.begin();
    }

    //start k
    for (int i=0;i<k;i++) {
        int input;
        cin>>input;
        s[input] = 1;
        max_size = max(max_size,1);
        all_size.insert(1);
        if (s[input-1]==1) merge(input,input-1);
        if (s[input+1]==1) merge(input,input+1);
        tmax+=max_size;
        tmin+=*all_size.begin();
    }
    cout << tmax << "\n" << tmin;
}