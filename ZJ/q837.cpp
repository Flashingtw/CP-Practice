#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int m,n,k;
    cin>>m>>n>>k;
    string a[m];
    int turn[k][m];

    for (int i=0;i<m;i++) {
        string inp;
        cin>>inp;
        a[i]=inp;
    }
    for (int i=0;i<k;i++) {
        for (int j=0;j<m;j++) {
            int inp;
            cin>>inp;
            turn[i][j] = inp;
        }
    }
    int ans =0;
    for (int i = 0;i<k;i++){
        for (int j = 0;j<m;j++) {
            int t = turn[i][j];
            t = t%n;
            if (t>0){
                rotate(a[j].begin(),a[j].begin()+t,a[j].end());
            }
            if (t<0) {
                rotate(a[j].begin(),a[j].begin()+n-t,a[j].end());
            }
        }
        for (int l =0;l<n;l++) {
            map<char,int> c;
            for (char b : a[l]) {
                c[b]++;
                cout << b;
            }
            char max = ' ';
            int max_count = 0;
            for (auto [nums,count] : c) {
                if (max_count<count) {
                    max = nums;
                }
            }
            ans+=max_count;
        }
    }
    cout << ans << "\n";
}