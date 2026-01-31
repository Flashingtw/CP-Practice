#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    map<int,int,greater<int>> s;
    int a,b,c;
    cin >> a>>b>>c;
    s[a]++;
    s[b]++;
    s[c]++;
    int max_num=0;
    for (auto i : s) {
        if (i.second>max_num) {
            max_num = i.second;
        }
    }
    cout << max_num << " ";
    for (auto i : s) {
        cout << i.first << " ";
    }
}