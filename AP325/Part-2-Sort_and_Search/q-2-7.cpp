#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int ff = (1<<m)-1;// if m=4 (1<<4)-1 -> 11111-1=01111 全位元遮罩

    vector<int> v(n,1);
    for (int i=0;i<n;i++) {
        string s;
        cin>>s;
        int current =0;
        for (char c :s) {
            current |= 1<<(c-'A');
        }
        v[i] = current;
    }
    sort(v.begin(),v.end());
    int count = 0;
    for (int i=0;i<n;i++) {
        int t = ff ^ v[i];
        if (binary_search(v.begin(),v.end(),t)) count++;
    }
    cout << count/2;
}