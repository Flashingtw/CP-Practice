#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int cnt[101];
int main(){
    for(int i=1;i<=100;i++) cnt[i] = cnt[i-1]+i;
    int n;
    cin>>n;
    while(n>0){
        int idx = upper_bound(cnt+1,cnt+101,n)-cnt-1;
        for(int i=0;i<idx;i++) cout << 'a';
        cout << ' '; 
        n-=cnt[idx];
    }
}