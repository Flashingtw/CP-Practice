#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin>>n;
    string a[n];
    map<string,int> mp;
    for (int i=0;i<n;++i) {
        cin>>a[i];
        int s_odd=0,s_even=0;
        for (int j=1;j<=12;++j) {
            if (j%2==1) {
                s_odd+=a[i][j-1]-'0';
            }else {
                s_even+=a[i][j-1]-'0';
            }
        }
        if (const int ch = (s_odd+3*s_even)%10+(a[i][12] - '0'); ch==0||ch==10) {
            mp[a[i].substr(0,3)] +=1;
        }
    }
    int max = 0;
    string max_str;
    for (auto i : mp) {
        if (i.second > max) {
            max = i.second;
            max_str = i.first;
        }
    }
    cout << max_str << " " << max;
}